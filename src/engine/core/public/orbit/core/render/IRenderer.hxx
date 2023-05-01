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

// Include orbit::core::Material
#ifndef ORBIT_CORE_MATERIAL_HPP
#include <orbit/core/assets/materials/Material.hpp>
#endif /// !ORBIT_CORE_MATERIAL_HPP

// Include orbit::core::Shader
#ifndef ORBIT_CORE_SHADER_HPP
#include <orbit/core/assets/shaders/Shader.hpp>
#endif /// !ORBIT_CORE_SHADER_HPP

// Include STL memory
#include <memory>

// Include STL string
#include <string>

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

            virtual std::shared_ptr<orbit_Material> createMaterial() = 0;

            virtual std::shared_ptr<orbit_Shader> createShader(const unsigned char shaderType, const std::string sourceFile) = 0;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// orbit::core::IRenderer

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// orbit::core

} /// orbit

using orbit_IRenderer = orbit::core::IRenderer;
#define ORBIT_CORE_I_RENDERER_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ORBIT_CORE_I_RENDERER_HXX
