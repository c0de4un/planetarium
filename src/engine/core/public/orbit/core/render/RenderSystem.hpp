/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORBIT_CORE_RENDER_SYSTEM_HPP
#define ORBIT_CORE_RENDER_SYSTEM_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include orbit::core::System
#ifndef ORBIT_CORE_SYSTEM_HPP
#include <orbit/core/ecs/System.hpp>
#endif /// !ORBIT_CORE_SYSTEM_HPP

// Include orbit::core::IRenderer
#ifndef ORBIT_CORE_I_RENDERER_HXX
#include <orbit/core/render/IRenderer.hxx>
#endif /// !ORBIT_CORE_I_RENDERER_HXX

// Include STL memory
#include <memory>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // RenderSystem
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        class RenderSystem : public System, public IRenderer
        {

        protected:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static std::shared_ptr<RenderSystem> mInstance;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            explicit RenderSystem();

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            RenderSystem(const RenderSystem&)            = delete;
            RenderSystem& operator=(const RenderSystem&) = delete;
            RenderSystem(RenderSystem&&)                 = delete;
            RenderSystem& operator=(RenderSystem&&)      = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual ~RenderSystem() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static std::shared_ptr<RenderSystem> getInstance();
            static bool isInitialized() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.RenderSystem
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static std::shared_ptr<RenderSystem> Initialize(std::shared_ptr<RenderSystem> pInstance);
            static void Terminate() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// orbit::core::System

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// orbit::core

} /// orbit

using orbit_Renderer = orbit::core::RenderSystem;
#define ORBIT_CORE_RENDER_SYSTEM_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ORBIT_CORE_RENDER_SYSTEM_HPP