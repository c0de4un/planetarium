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

// Include orbit::core::AssetsManager
#ifndef ORBIT_CORE_ASSETS_MANAGER_HPP
#include <orbit/core/assets/AssetsManager.hpp>
#endif /// !ORBIT_CORE_ASSETS_MANAGER_HPP

// Include Planet
#ifndef ORBIT_CORE_PLANET_HPP
#include <core/objects/Planet.hpp>
#endif /// !ORBIT_CORE_PLANET_HPP

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
            std::shared_ptr<orbit_Scene3D> scene( std::make_shared<orbit_Scene3D>() );
            mScene3D = std::static_pointer_cast<orbit_IScene, orbit_Scene3D>( scene );

            // Get AssetsManager
            std::shared_ptr<orbit_Assets> assetsManager( orbit_Assets::getInstance() );

            // @TODO: Create Material
            std::shared_ptr<orbit_Material> planetMaterial( assetsManager->createMaterial() );

            // @TODO: Load VertexShader
            std::shared_ptr<orbit_IShader> vertexShader( assetsManager->createShader(orbit_EShaderTypes::SHADER_TYPE_VERTEX, std::string("assets/shaders/vertex.glsl")) );

            planetMaterial->attachSlot( orbit_EMaterialSlots::MATERIAL_SLOT_VERTEX_SHADER, std::static_pointer_cast<orbit_IMaterialSlot, orbit_IShader>(vertexShader) );
            //planetMaterial->attachSlot(EMaterialSlots::MATERIAL_SLOT_VERTEX_SHADER, vertexShader);

            // @TODO: Load Fragment Shader
            //planetMaterial->attachSlot(EMaterialSlots::MATERIAL_SLOT_FRAGMENT_SHADER, fragmentShader);

            // @TODO: Load Geometry Shader

            // @TODO: Load Texture2D
            //planetMaterial->attachSlot(EMaterialSlots::MATERIAL_SLOT_TEXTURE_2D, planetDiffuseTexture2D);

            // Create Planet
            std::shared_ptr<orbit_Planet> planet( std::make_shared<orbit_Planet>() );

            // @TODO: Attach Assets to Planet
            planet->setMaterial(planetMaterial);

            // @TODO: Attach Planet to Scene
            scene->attachObject( std::static_pointer_cast<orbit_GameObject, orbit_Planet>(planet) );

            // Load Scene and attached Objects
            if (!scene->Load())
            {
#ifdef ORBIT_DEBUG // DEBUG
                orbit_Log::error("OrbitGame::onLoad: failed to load 3D Scene");
#endif // DEBUG

                return false;
            }

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
