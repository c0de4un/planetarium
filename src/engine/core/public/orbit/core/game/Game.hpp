/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORBIT_CORE_GAME_HPP
#define ORBIT_CORE_GAME_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include STL memory
#include <memory>

// Include orbit::core::System
#ifndef ORBIT_CORE_SYSTEM_HPP
#include <orbit/core/ecs/System.hpp>
#endif /// !ORBIT_CORE_SYSTEM_HPP

// Include orbit::core::IGame
#ifndef ORBIT_CORE_I_GAME_HXX
#include <orbit/core/game/IGame.hxx>
#endif /// !ORBIT_CORE_I_GAME_HXX

// Include orbit::core::IRenderLsitener
#ifndef ORBIT_CORE_I_RENDER_LSITENER_HXX
#include <orbit/core/render/IRenderListener.hxx>
#endif /// !ORBIT_CORE_I_RENDER_LSITENER_HXX

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Game
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // Game
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        class Game : public orbit_System, public orbit_IGame, public orbit_IRenderListener
        {

        protected:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static std::shared_ptr<Game> mInstance;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            explicit Game();

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.System
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual bool onStart() override;
            virtual bool onResume() override;
            virtual bool onPause() override;
            virtual void onStop() override;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DELETED
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            Game(const Game&)            = delete;
            Game& operator=(const Game&) = delete;
            Game(Game&&)                 = delete;
            Game& operator=(Game&&)      = delete;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public:

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual ~Game() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static std::shared_ptr<Game> getInstance();
            static bool isInitialized() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.IGame
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            virtual bool onError(const char* const msg) noexcept override;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.IRenderListener
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            void onRender() override;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS.Game
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            static std::shared_ptr<Game> Initialize(std::shared_ptr<Game> pInstance);
            static void Terminate() noexcept;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }; /// orbit::core::Game

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    } /// orbit::core

} /// orbit

using orbit_Game = orbit::core::Game;
#define ORBIT_CORE_GAME_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ORBIT_CORE_GAME_HPP
