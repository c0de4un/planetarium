/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORBIT_WIN_GRAPHICS_HPP
#define ORBIT_WIN_GRAPHICS_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include orbit::core::Graphics
#ifndef ORBIT_CORE_GRAPHICS_HPP
#include <orbit/core/graphics/Graphics.hpp>
#endif /// !ORBIT_CORE_GRAPHICS_HPP

// Include orbit::gl
#ifndef ORBIT_GL_HPP
#include <orbit/gl/config/orbit_gl.hpp>
#endif /// !ORBIT_GL_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace win
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // WinGraphics
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        class WinGraphics final : public orbit_Graphics
        {

        protected:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            GLFWwindow* mWindow;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.System
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual bool onStart()  final;
            virtual bool onResume() final;
            virtual bool onPause()  final;
            virtual void onStop()   final;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR & DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            explicit WinGraphics();
            virtual ~WinGraphics() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static void onError(int error, const char* description);

            static void onKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods);

            void Loop();

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// orbit::win::WinGraphics

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// orbit::win

} /// orbit

using orbit_WinGraphics = orbit::win::WinGraphics;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ORBIT_WIN_GRAPHICS_HPP
