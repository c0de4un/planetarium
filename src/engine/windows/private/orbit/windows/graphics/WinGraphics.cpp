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

// Include orbit::gl::GLRenderer
#ifndef ORBIT_GL_RENDERER_HPP
#include <orbit/gl/render/GLRenderer.hpp>
#endif /// !ORBIT_GL_RENDERER_HPP

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
            : Graphics(),
            mWindow(nullptr)
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

            // Check RenderSystem
#ifdef ORBIT_DEBUG // DEBUG
            assert(orbit_Renderer::isInitialized() && "WinGraphics::onStart: missing RenderSystem");
#else // !DEBUG
            if (!orbit_Renderer::isInitialized())
                return false;
#endif // DEBUG

            glfwSetErrorCallback(WinGraphics::onError);

            if (!glfwInit())
            {
#ifdef ORBIT_DEBUG // DEBUG
                throw new std::exception("failed to initialize GLFW");
#else // !DEBUG
                return false;
#endif // DEBUG
            }

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ORBIT_GL_MAJOR);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, ORBIT_GL_MINOR);
            mWindow = glfwCreateWindow(640, 480, "Orbit", nullptr, nullptr);
#ifdef ORBIT_DEBUG // DEBUG
            assert(mWindow && "WinGraphics::onStart: Window or OpenGL context creation failed");
#else // !DEBUG
            return false;
#endif // DEBUG

            glfwMakeContextCurrent(mWindow);

            gladLoadGL(glfwGetProcAddress);

            glfwSetKeyCallback(mWindow, WinGraphics::onKeyInput);

            setState(WinGraphics::STATE_RUNNING);

            // Start GLRenderer
            std::shared_ptr<orbit_GLRenderer> glRenderer( std::static_pointer_cast<orbit_GLRenderer, orbit_Renderer>(orbit_Renderer::getInstance()) );
            const bool result( glRenderer->Start() );
            if (!result)
            {
#ifdef ORBIT_DEBUG // DEBUG
                assert(mWindow && "WinGraphics::onStart: Failed to start GLRenderer");
#else // !DEBUG
                return false;
#endif // DEBUG
            }

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

            glfwDestroyWindow(mWindow);
            mWindow = nullptr;

            glfwTerminate();

            setState(WinGraphics::STATE_NONE);
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void WinGraphics::onError(int error, const char* description)
        {
#ifdef ORBIT_DEBUG // DEBUG
            std::string logMsg("WinGraphics::onError: code=");
            logMsg += std::to_string(error);
            logMsg += "; description=";
            logMsg += description;
            orbit_Log::error(logMsg.c_str());
#endif // DEBUG
        }

        void WinGraphics::onKeyInput(GLFWwindow* window, int key, int scanCode, int action, int mods)
        {
            std::shared_ptr<WinGraphics> winGraphics( std::static_pointer_cast<orbit_WinGraphics, orbit_Graphics>(mInstance) );

            if (!winGraphics || !winGraphics->isStarted() || winGraphics->isPaused())
                return;

#ifdef ORBIT_DEBUG // DEBUG
            std::string logMsg("WinGraphics::onKeyInput: key=");
            logMsg += std::to_string(key);
            logMsg += "; scanCode=";
            logMsg += std::to_string(scanCode);
            logMsg += "; action=";
            logMsg += std::to_string(action);
            logMsg += "; mods=";
            logMsg += std::to_string(mods);
            orbit_Log::debug(logMsg.c_str());
#endif // DEBUG

            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(winGraphics->mWindow, GLFW_TRUE);
        }

        void WinGraphics::Loop()
        {
            // GLRenderer
            std::shared_ptr<orbit_GLRenderer> glRenderer( std::static_pointer_cast<orbit_GLRenderer, orbit_Renderer>(orbit_Renderer::getInstance()) );

#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("WinGraphics::Loop");
            assert(isStarted() && "WinGraphics::Loop: not started");
            assert(!glfwWindowShouldClose(mWindow) && "WinGraphics::Loop: !glfwWindowShouldClose");
            assert(glRenderer->isStarted() && "WinGraphics::Loop: Render system is not started");
            assert(!glRenderer->isPaused() && "WinGraphics::Loop: Render system is paused");
#endif // DEBUG

            while (isStarted() && !glfwWindowShouldClose(mWindow))
            {
                if (glRenderer->isStarted() && !glRenderer->isPaused())
                    glRenderer->Draw();

                glfwSwapBuffers(mWindow);

                glfwPollEvents();
            }

            Stop();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
