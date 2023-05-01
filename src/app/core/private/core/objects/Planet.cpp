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
            : GameObject()
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
        //
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
