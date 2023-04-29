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
#ifndef ORBIT_WIN_GRAPHICS_HPP
#include <orbit/windows/graphics/WinGraphics.hpp>
#endif /// !ORBIT_WIN_GRAPHICS_HPP

// Include orbit::gl
#ifndef ORBIT_GL_HPP
#include <orbit/gl/config/orbit_gl.hpp>
#endif /// !ORBIT_GL_HPP

// DEBUG
#ifdef ORBIT_DEBUG

// Include orbit::debug
#ifndef ORBIT_CORE_DEBUG_HPP
#include <orbit/core/cfg/orbit_debug.hpp>
#endif /// !ORBIT_CORE_DEBUG_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// WinGraphics
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace win
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        WinGraphics::WinGraphics()
            : Graphics()
        {
        }

        WinGraphics::~WinGraphics() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.System
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool WinGraphics::onStart()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("WinGraphics::onStart");
#endif // DEBUG

            setState(WinGraphics::STATE_RUNNING);

            return true;
        }

        bool WinGraphics::onResume()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("WinGraphics::onResume");
#endif // DEBUG

            setState(WinGraphics::STATE_RUNNING);

            return true;
        }

        bool WinGraphics::onPause()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("WinGraphics::onPause");
#endif // DEBUG

            setState(WinGraphics::STATE_PAUSED);

            return true;
        }

        void WinGraphics::onStop()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("WinGraphics::onStop");
#endif // DEBUG

            setState(WinGraphics::STATE_NONE);
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
