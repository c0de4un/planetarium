/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef ORBIT_CORE_BATCH_REQUEST_HPP
#define ORBIT_CORE_BATCH_REQUEST_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include orbit::core::Component
#ifndef ORBIT_CORE_COMPONENT_HPP
#include <orbit/core/ecs/Component.hpp>
#endif /// !ORBIT_CORE_COMPONENT_HPP

// Include orbit::core::IDrawable
#ifndef ORBIT_CORE_I_DRAWABLE_HXX
#include <orbit/core/render/IDrawable.hxx>
#endif /// !ORBIT_CORE_I_DRAWABLE_HXX

// Include orbit::core::Material
#ifndef ORBIT_CORE_MATERIAL_HPP
#include <orbit/core/assets/materials/Material.hpp>
#endif /// !ORBIT_CORE_MATERIAL_HPP

// Include orbit::core::IMesh
#ifndef ORBIT_CORE_I_MESH_HXX
#include <orbit/core/mesh/IMesh.hxx>
#endif /// !ORBIT_CORE_I_MESH_HXX

// Include STL memory
#include <memory>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // BatchRequest
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        struct BatchRequest : public orbit_Component
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTANTS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            const bool         mTransparent;
            const unsigned int mZOrder;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELD
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            std::weak_ptr<orbit_IDrawable> mDrawable;
            std::weak_ptr<orbit_Material>  mMaterial;
            std::weak_ptr<orbit_IMesh>     mMesh;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        };

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

using orbit_BatchRequest = orbit::core::BatchRequest;
#define ORBIT_CORE_BATCH_REQUEST_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ORBIT_CORE_BATCH_REQUEST_HPP
