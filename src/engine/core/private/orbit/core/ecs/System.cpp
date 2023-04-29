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
#ifndef ORBIT_CORE_SYSTEM_HPP
#include <orbit/core/ecs/System.hpp>
#endif /// !ORBIT_CORE_SYSTEM_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// System
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        System::System()
            :
            mState(System::STATE_NONE)
        {
        }

        System::~System() noexcept
        {
            Stop();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void System::setState(const System::state_t state) noexcept
        {
            mState = state;
        }

        bool System::isStarted() const noexcept
        {
            const System::state_t state(mState);

            return state > System::STATE_NONE;
        }

        bool System::isPaused() const noexcept
        {
            const System::state_t state(mState);

            return state > System::STATE_RUNNING && state < System::STATE_PAUSING;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.System
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool System::onStart()
        {
            return true;
        }

        bool System::onResume()
        {
            return true;
        }

        bool System::onPause()
        {
            return true;
        }

        void System::onStop()
        {
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.ISystem
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool System::Start()
        {
            if (isStarted()) {
                if (isPaused())
                {
                    setState(System::STATE_STARTING);

                    return onResume();
                }

                return true;
            }

            setState(System::STATE_STARTING);

            return onStart();
        }

        bool System::Pause()
        {
            if (!isStarted() || isPaused())
                return true;

            setState(System::STATE_PAUSING);

            return onPause();
        }

        void System::Stop() noexcept
        {
            if (!isStarted())
                return;

            setState(System::STATE_STOPPING);

            onStop();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
