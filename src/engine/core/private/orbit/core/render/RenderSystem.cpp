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
#ifndef ORBIT_CORE_RENDER_SYSTEM_HPP
#include <orbit/core/render/RenderSystem.hpp>
#endif /// !ORBIT_CORE_RENDER_SYSTEM_HPP

#ifdef ORBIT_DEBUG // DEBUG

// Include orbit::debug
#ifndef ORBIT_CORE_DEBUG_HPP
#include <orbit/core/cfg/orbit_debug.hpp>
#endif /// !ORBIT_CORE_DEBUG_HPP

#endif // DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// RenderSystem
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // FIELDS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        std::shared_ptr<RenderSystem> RenderSystem::mInstance(nullptr);

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        RenderSystem::RenderSystem()
            :
            System(),
            mListenersMutex(),
            mListeners()
        {
        }

        RenderSystem::~RenderSystem() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        std::shared_ptr<RenderSystem> RenderSystem::getInstance()
        {
            return mInstance; // Copy and increase ref counter
        }

        bool RenderSystem::isInitialized() noexcept
        {
            return static_cast<bool>(mInstance.get());
        }

        std::shared_ptr<orbit_IRenderListener> RenderSystem::getNextListener(size_t index) const
        {
            std::unique_lock<std::mutex> lock(mListenersMutex);

            const size_t listenersCount(mListeners.size());
            if (mListeners.empty() || !listenersCount || (listenersCount - 1) < index)
                return std::shared_ptr<orbit_IRenderListener>(nullptr);

            return mListeners.at(index);
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.System
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void RenderSystem::onStop()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("RenderSystem::onStop");
#endif // DEBUG

            try
            {
                std::unique_lock<std::mutex> lock(mListenersMutex);

                mListeners.clear();

                lock.unlock();
            }
            catch (...) // mutex may throw exception
            {
                // void
            }

            System::onStop();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.RenderSystem
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        std::shared_ptr<RenderSystem> RenderSystem::Initialize(std::shared_ptr<RenderSystem> pInstance)
        {
#ifdef ORBIT_DEBUG // DEBUG
            assert(!mInstance.get() && "RenderSystem::Initialize: already initialized");
            orbit_Log::info("RenderSystem::Initialize");
#endif // DEBUG
            if (!mInstance.get())
                mInstance = pInstance; // Copy

            return mInstance;
        }

        void RenderSystem::Terminate() noexcept
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("RenderSystem::Terminate");
#endif // DEBUG
            mInstance.reset();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.IRenderer
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void RenderSystem::addListener(std::shared_ptr<orbit_IRenderListener> pListener)
        {
            std::unique_lock<std::mutex>(mListenersMutex);

            mListeners.push_back(pListener); // Copy instead of move
        }

        void RenderSystem::removeListener(std::shared_ptr<orbit_IRenderListener> pListener)
        {
            std::unique_lock<std::mutex>(mListenersMutex);

            const auto begin_it( mListeners.cbegin() );
            const auto end_it( mListeners.cend() );
            auto iterator( mListeners.begin() );

            while (iterator != end_it)
            {
                if (iterator->get() == pListener.get())
                {
                    mListeners.erase(iterator);
                    break;
                }

                iterator++;
            }
        }

        std::shared_ptr<orbit_IMaterial> RenderSystem::createMaterial()
        {
#ifdef ORBIT_DEBUG // DEBUG
            throw new std::exception("RenderSystem::createMaterial: not implemented");
#endif // DEBUG

            return std::shared_ptr<orbit_IMaterial>(nullptr);
        }

        std::shared_ptr<orbit_IShader> RenderSystem::createShader(const unsigned char shaderType, const std::string sourceFile)
        {
#ifdef ORBIT_DEBUG // DEBUG
            throw new std::exception("RenderSystem::createShader: not implemented");
#endif // DEBUG

            return std::shared_ptr<orbit_IShader>(nullptr);
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
