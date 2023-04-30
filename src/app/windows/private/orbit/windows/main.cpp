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
#include <orbit/windows/main.hpp>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MAIN
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void Start()
{
#ifdef ORBIT_DEBUG // DEBUG
    // Initialize Logger
    orbit_Log::Initialize(std::static_pointer_cast<orbit_ConsoleLogger, orbit_ILogger>( std::make_shared<orbit_ConsoleLogger>() ));

    orbit_Log::info("Starting . . .");
#endif // DEBUG

    // Guarded-Block
    try
    {
        // Initialize AssetsManager
        orbit_Assets::Initialize( std::make_shared<orbit_Assets>() );

        // Initialize WinGraphics
        std::shared_ptr<orbit_WinGraphics> winGraphics(std::static_pointer_cast<orbit_WinGraphics, orbit_Graphics>(orbit_Graphics::Initialize(std::static_pointer_cast<orbit_WinGraphics, orbit_Graphics>( std::make_shared<orbit_WinGraphics>() ))));

        // Initialize GLRenderer
        orbit_Renderer::Initialize(std::static_pointer_cast<orbit_Renderer, orbit_GLRenderer>(std::make_shared<orbit_GLRenderer>()));

        // Initialize OrbitGame
        std::shared_ptr<orbit::core::OrbitGame> game(std::make_shared<orbit::core::OrbitGame>());
        orbit_Game::Initialize(std::static_pointer_cast<orbit_Game, orbit::core::OrbitGame>(game));

#ifdef ORBIT_DEBUG
        assert(orbit_Game::getInstance() == game && "main::Start: Unexpected Game initialization result");
#endif

        // Start
        if (!game->Start())
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::error("main::Start: failed to Start Game");
#endif // DEBUG

            return;
        }

        // Enter render loop
        winGraphics->Loop();
    }
#ifdef ORBIT_DEBUG // DEBUG
    catch(const std::exception& exception_ref)
    {
        std::string logMsg("main::Start: ");
        logMsg += exception_ref.what();
        orbit_Log::error(logMsg.c_str());
    }
#endif // DEBUG
    catch (...)
    {
#ifdef ORBIT_DEBUG // DEBUG
        std::string logMsg("main::Start: unknown error");
        orbit_Log::error(logMsg.c_str());
#endif // DEBUG
    }
}

void Stop()
{
#ifdef ORBIT_DEBUG // dEBUG
    orbit_Log::info("Stopping . . .");
#endif // DEBUG

    // Guarded-Block
    try
    {
        // Stop Game, Engine, Graphics, etc
        std::shared_ptr<orbit_Game> game(orbit_Game::getInstance());
        if (game.get())
            game->Stop();

        // Terminate Instances
        orbit_Game::Terminate();

        // Terminate AssetsManager
        orbit_Assets::Terminate();

#ifdef ORBIT_DEBUG // dEBUG
    orbit_Log::Terminate();
#endif // DEBUG
    }
#ifdef ORBIT_DEBUG // DEBUG
    catch(const std::exception& exception_ref)
    {
        std::string logMsg("main::Stop: ");
        logMsg += exception_ref.what();
        orbit_Log::error(logMsg.c_str());
    }
#endif // DEBUG
    catch (...)
    {
#ifdef ORBIT_DEBUG // DEBUG
        std::string logMsg("main::Stop: unknown error");
        orbit_Log::error(logMsg.c_str());
#endif // DEBUG
    }
}

int main()
{
    Start();
    Stop();

    return ORBIT_OK;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
