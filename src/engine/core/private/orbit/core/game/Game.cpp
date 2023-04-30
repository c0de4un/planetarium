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
#ifndef ORBIT_CORE_GAME_HPP
#include <orbit/core/game/Game.hpp>
#endif /// !ORBIT_CORE_GAME_HPP

// Include orbit::core::Graphics
#ifndef ORBIT_CORE_GRAPHICS_HPP
#include <orbit/core/graphics/Graphics.hpp>
#endif /// !ORBIT_CORE_GRAPHICS_HPP

// Include orbit::core::RenderSystem
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
// Game
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // FIELDS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        std::shared_ptr<Game> Game::mInstance(nullptr);

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Game::Game()
            : System()
        {
        }

        Game::~Game() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        std::shared_ptr<Game> Game::getInstance()
        {
            return mInstance; // Intentionally copy ref
        }

        bool Game::isInitialized() noexcept
        {
            return static_cast<bool>(mInstance.get());
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.IGame
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Game::onError(const char* const msg) noexcept
        {
#ifdef ORBIT_DEBUG // DEBUG
            std::string logMsg("Game::onError: ");
            logMsg += msg;
            orbit_Log::error(logMsg.c_str());
#endif // DEBUG

            // Stop Game, Engine, Graphic, Audio, Input, etc
            Stop();

            return true;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.System
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Game::onStart()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("Game::onStart");
#endif // DEBUG

            // Check RenderSystem
#ifdef ORBIT_DEBUG // DEBUG
            assert(orbit_Renderer::isInitialized() && "Game::onStart: RenderSystem is not initialized");
#else // !DEBUG
            if (!orbit_Renderer::isInitialized())
                return false;
#endif // DEBUG
            
            // Check Graphics System
#ifdef ORBIT_DEBUG // DEBUG
            assert(orbit_Graphics::isInitialized() && "Game::onStart: Graphics system is not initialized");
#else // !DEBUG
            if (!orbit_Graphics::isInitialized())
                return false;
#endif // DEBUG

            // Start Graphics with Renderer
            bool result(orbit_Graphics::getInstance()->Start());
#ifdef ORBIT_DEBUG // DEBUG
            assert(result && "Game::onStart: failed to Start Graphics system");
#else // !DEBUG
            return false;
#endif // DEBUG

            setState(Game::STATE_RUNNING);

            return true;
        }

        bool Game::onResume()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("Game::onResume");
#endif // DEBUG

            return onStart();
        }

        bool Game::onPause()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("Game::onPause");
#endif // DEBUG

            setState(Game::STATE_PAUSED);

            return true;
        }

        void Game::onStop()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("Game::onStop");
#endif // DEBUG

            // Stop RenderSystem
            std::shared_ptr<orbit_Renderer> renderSystem(orbit_Renderer::getInstance());
            if (renderSystem.get())
                renderSystem->Stop();
            renderSystem = nullptr;

            // Stop Graphics
            std::shared_ptr<orbit_Graphics> graphicsSystem(orbit_Graphics::getInstance());
            if (graphicsSystem.get())
                graphicsSystem->Stop();
            graphicsSystem = nullptr;

            setState(Game::STATE_NONE);
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.Game
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
