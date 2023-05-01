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
#ifndef ORBIT_CORE_PLANET_HPP
#include <core/objects/Planet.hpp>
#endif /// !ORBIT_CORE_PLANET_HPP

// Include orbit::core::RenderSystem
#ifndef ORBIT_CORE_RENDER_SYSTEM_HPP
#include <orbit/core/render/RenderSystem.hpp>
#endif /// !ORBIT_CORE_RENDER_SYSTEM_HPP

#ifdef ORBIT_DEBUG // DEBUG

#ifndef ORBIT_CORE_DEBUG_HPP
#include <orbit/core/cfg/orbit_debug.hpp>
#endif /// !ORBIT_CORE_DEBUG_HPP

#endif // DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Planet
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Planet::Planet()
            : GameObject(),
            mMaterial(nullptr),
            mSphereMesh(nullptr)
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::debug("Planet::construct");
#endif // DEBUG
        }

        Planet::~Planet() noexcept
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::debug("Planet::destruct");
#endif // DEBUG
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.GameObject
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Planet::onLoad()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::debug("Planet::onLoad");
#endif // DEBUG

            // Get RenderSystem
            std::shared_ptr<orbit_Renderer> renderSystem(orbit_Renderer::getInstance());

            // @TODO: Load Mesh
            mSphereMesh = renderSystem->createSphere3D();

            return GameObject::onLoad();
        }

        void Planet::onUnload()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::debug("Planet::onUnload");
#endif // DEBUG

            GameObject::onUnload();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void Planet::setMaterial(std::shared_ptr<orbit_Material> mat)
        {
            mMaterial = mat; // Copy

            attachAsset( std::static_pointer_cast<orbit_Asset, orbit_Material>(mMaterial) );
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
