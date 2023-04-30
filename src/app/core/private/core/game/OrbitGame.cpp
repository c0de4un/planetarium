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
#ifndef ORBIT_GAME_HPP
#include <core/game/OrbitGame.hpp>
#endif /// !ORBIT_GAME_HPP

// Include orbit::core::Scene3D
#ifndef ORBIT_CORE_SCENE_3D_HPP
#include <orbit/core/scene/Scene3D.hpp>
#endif /// !ORBIT_CORE_SCENE_3D_HPP

#ifdef ORBIT_DEBUG /// DEBUG

#ifndef ORBIT_CORE_DEBUG_HPP
#include <orbit/core/cfg/orbit_debug.hpp>
#endif /// !ORBIT_CORE_DEBUG_HPP

#endif /// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// OrbitGame
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        OrbitGame::OrbitGame()
            : Game(),
            mCamera3D(nullptr),
            mScene3D(nullptr)
        {
        }

        OrbitGame::~OrbitGame() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.Game
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool OrbitGame::onLoad()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("OrbitGame::onLoad");
#endif // DEBUG

            // Create Camera3D for 3D Scene
            mCamera3D = std::make_shared<orbit_Camera3D>();

            // Create 3D Scene
            mScene3D = std::static_pointer_cast<orbit_IScene, orbit_Scene3D>( std::make_shared<orbit_Scene3D>() );

            return Game::onLoad();
        }

        bool OrbitGame::onStart()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("OrbitGame::onStart");
#endif // DEBUG

            return Game::onStart();
        }

        void OrbitGame::onRender()
        {
            if (!isStarted() || isPaused())
                return;

            // Draw 3D Scene
            mCamera3D->RenderScene(mScene3D);
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
