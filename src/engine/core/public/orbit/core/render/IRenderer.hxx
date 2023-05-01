/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORBIT_CORE_I_RENDERER_HXX
#define ORBIT_CORE_I_RENDERER_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include orbit::core::IRenderLsitener
#ifndef ORBIT_CORE_I_RENDER_LSITENER_HXX
#include <orbit/core/render/IRenderListener.hxx>
#endif /// !ORBIT_CORE_I_RENDER_LSITENER_HXX

// Include orbit::core::IMaterial
#ifndef ORBIT_CORE_I_MATERIAL_HXX
#include <orbit/core/assets/materials/IMaterial.hxx>
#endif /// !ORBIT_CORE_I_MATERIAL_HXX

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
        // IRenderer
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        class IRenderer
        {

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual ~IRenderer() noexcept = default;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual void addListener(std::shared_ptr<orbit_IRenderListener> pListener)    = 0;
            virtual void removeListener(std::shared_ptr<orbit_IRenderListener> pListener) = 0;

            virtual std::shared_ptr<orbit_IMaterial> createMaterial() = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// orbit::core::IRenderer

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// orbit::core

} /// orbit

using orbit_IRenderer = orbit::core::IRenderer;
#define ORBIT_CORE_I_RENDERER_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ORBIT_CORE_I_RENDERER_HXX
