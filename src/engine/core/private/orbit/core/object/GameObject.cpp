/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// HEADER
#ifndef ORBIT_CORE_GAME_OBJECT_HPP
#include <orbit/core/object/GameObject.hpp>
#endif /// !ORBIT_CORE_GAME_OBJECT_HPP

#ifdef ORBIT_DEBUG // DEBUG

// Inlcude orbig::debug
#ifndef ORBIT_CORE_DEBUG_HPP
#include <orbit/core/cfg/orbit_debug.hpp>
#endif /// !ORBIT_CORE_DEBUG_HPP

#endif // DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// GameObject
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        GameObject::GameObject()
            :
            Entity(),
            mLoaded(false),
            mChildrenMutex(),
            mChildren(),
            mParent(nullptr),
            mAssetsMutex(),
            mAssets()
        {
        }

        GameObject::~GameObject() noexcept
        {
            Unload();

            removeChildren();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool GameObject::isLoaded() const noexcept
        {
            return mLoaded;
        }

        bool GameObject::isAttached() const noexcept
        {
            return mParent;
        }

        std::shared_ptr<GameObject> GameObject::getNextChild(const size_t iter) const
        {
            std::unique_lock<std::mutex> lock( mChildrenMutex );

            if (mChildren.empty() || mChildren.size() < (iter - 1))
                return std::shared_ptr<GameObject>(nullptr);

            return mChildren.at(iter);
        }

        std::shared_ptr<orbit_Asset> GameObject::getNextAsset(const size_t iter) const
        {
            std::unique_lock<std::mutex> lock( mAssetsMutex );

            if (mAssets.empty() || mAssets.size() < (iter - 1))
                return std::shared_ptr<orbit_Asset>(nullptr);

            return mAssets.at(iter);
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.GameObject
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void GameObject::removeChildren() noexcept
        {
            std::unique_lock<std::mutex> lock( mChildrenMutex );

            const auto end_iter( mChildren.cend() );
            auto iter( mChildren.begin() );
            while (iter != end_iter)
            {
                auto ptr( iter->get() );
                if (ptr)
                    ptr->onDetaching();
            }
        }

        bool GameObject::onAttaching(GameObject* const parent)
        {
            mParent = parent;

            return true;
        }

        void GameObject::onDetaching()
        {
            mParent = nullptr;
        }

        bool GameObject::attachObject(object_ptr pChild)
        {
#ifdef ORBIT_DEBUG // DEBUG
            assert(static_cast<bool>( pChild.get() ) && "GameObject::attachObject: nullptr");
            assert(!pChild->isAttached() && "GameObject::attachObject: already attached");
#else
            if ( pChild.get() )
                return false;
#endif // DEBUG

            if (!pChild->onAttaching(this))
                return false;

            std::unique_lock<std::mutex> lock( mChildrenMutex );

            const size_t childrenCount( mChildren.size() );
            size_t iter(0);
            if (childrenCount)
            {
                while (iter < (childrenCount - 1))
                {
                    object_ptr &object_ptr(mChildren.at(iter));
                    if (!object_ptr.get())
                    {
                        object_ptr = pChild;
                        return true;
                    }

                    iter++;
                }
            }

            mChildren.push_back(pChild);

            return true;
        }

        bool GameObject::attachObject(GameObject* pChild)
        {
            return attachObject( object_ptr(pChild) );
        }

        void GameObject::detachObject(GameObject* pChild)
        {
            std::unique_lock<std::mutex> lock( mChildrenMutex );

            const auto end_iter( mChildren.cend() );
            auto iter( mChildren.begin() );
            while (iter != end_iter)
            {
                if (iter->get() == pChild)
                {
                    pChild->onDetaching();
                    iter->reset();
                    break;
                }

                iter++;
            }
        }

        void GameObject::attachAsset(std::shared_ptr<orbit_Asset> pAsset)
        {
            std::unique_lock<std::mutex> lock( mAssetsMutex );

            pAsset->addUser();

            mAssets.push_back(pAsset);
        }

        void GameObject::detachAsset(orbit_Asset* const pAsset)
        {
            std::unique_lock<std::mutex> lock( mAssetsMutex );

            const size_t assetsCount(mAssets.size());
            for (size_t i = 0; i < assetsCount; i++)
            {
                std::shared_ptr<orbit_Asset> &attachedAsset_ref(mAssets[i]);
                if (!attachedAsset_ref.get())
                    continue;

                if (attachedAsset_ref.get() == pAsset)
                {
                    pAsset->removeUser();
                    pAsset->Unload();
                    attachedAsset_ref.reset();
                    break;
                }
            }
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.ILoadable
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool GameObject::Load()
        {
            if (isLoaded())
                return true;

            // Load Assets
            size_t iter(0);
            std::shared_ptr<orbit_Asset> asset(nullptr);
            while (asset = getNextAsset(iter))
            {
                if (!asset->Load())
                {
                    if (!asset.get())
                        continue;

#ifdef ORBIT_DEBUG // DEBUG
                    orbit_Log::error("GameObject::Load: failed to load asset");
#endif // DEBUG
                    return false;
                }
            }

            // Load children
            iter = 0;
            std::shared_ptr<GameObject> child(nullptr);
            while (child = getNextChild(iter))
            {
                if (!child->Load())
                {
#ifdef ORBIT_DEBUG // DEBUG
                    orbit_Log::error("GameObject::Load: failed to load child");
#endif // DEBUG
                    return false;
                }

                iter++;
            }

            mLoaded = true;

            return true;
        }

        void GameObject::Unload()
        {
            if (!isLoaded())
                return;

            // Unload Assets
            size_t iter(0);
            std::shared_ptr<orbit_Asset> asset(nullptr);
            while (asset = getNextAsset(iter))
            {
                if (!asset.get())
                    continue;

                asset->Unload();
            }

            // Unload children
            iter = 0;
            std::shared_ptr<GameObject> child(nullptr);
            while (child = getNextChild(iter))
            {
                child->Unload();

                iter++;
            }

            mLoaded = false;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
