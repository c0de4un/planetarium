/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORBIT_CORE_GAME_OBJECT_HPP
#define ORBIT_CORE_GAME_OBJECT_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include orbit::core::Entity
#ifndef ORBIT_CORE_ENTITY_HPP
#include <orbit/core/ecs/Entity.hpp>
#endif /// !ORBIT_CORE_ENTITY_HPP

// Include orbit::core::ILoadable
#ifndef ORBIT_CORE_I_LOADABLE_HXX
#include <orbit/core/object/ILoadable.hxx>
#endif /// !ORBIT_CORE_I_LOADABLE_HXX

// Include orbit::core::Asset
#ifndef ORBIT_CORE_ASSET_HPP
#include <orbit/core/assets/Asset.hpp>
#endif /// !ORBIT_CORE_ASSET_HPP

// Include orbit::core::IDrawable
#ifndef ORBIT_CORE_I_DRAWABLE_HXX
#include <orbit/core/render/IDrawable.hxx>
#endif /// !ORBIT_CORE_I_DRAWABLE_HXX

// Include STL atomic
#include <atomic>

// Include STL memory
#include <memory>

// Include STL mutex
#include <mutex>

// Include STL vector
#include <vector>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GameObject
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        class GameObject : public orbit_Entity, public orbit_ILoadable, public orbit_IDrawable
        {

        private:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            void removeChildren() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        protected:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // ALIASES
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            using object_ptr = std::shared_ptr<GameObject>;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            std::atomic_bool        mLoaded;
            mutable std::mutex      mChildrenMutex;
            std::vector<object_ptr> mChildren;
            GameObject*             mParent;

            mutable std::mutex                         mAssetsMutex;
            std::vector<std::shared_ptr<orbit_Asset>> mAssets;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            explicit GameObject();

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            std::shared_ptr<GameObject> getNextChild(const size_t iter) const;

            std::shared_ptr<orbit_Asset> getNextAsset(const size_t iter) const;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.GameObject
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual bool onAttaching(GameObject* const parent);
            virtual void onDetaching();

            virtual bool onLoad();
            virtual void onUnload();

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            GameObject(const GameObject&)            = delete;
            GameObject& operator=(const GameObject&) = delete;
            GameObject(GameObject&&)                 = delete;
            GameObject& operator=(GameObject&&)      = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual ~GameObject() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual bool isLoaded() const noexcept final;

            bool isAttached() const noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.ILoadable
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual bool Load()   override;
            virtual void Unload() override;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.IDrawable
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual void Draw() override;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.GameObject
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual bool attachObject(object_ptr pChild);
            virtual bool attachObject(GameObject* const pChild);

            virtual void detachObject(GameObject* pChild);

            virtual void attachAsset(std::shared_ptr<orbit_Asset> pAsset);
            virtual void detachAsset(orbit_Asset* const pAsset);

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        };

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

using orbit_GameObject = orbit::core::GameObject;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ORBIT_CORE_GAME_OBJECT_HPP
