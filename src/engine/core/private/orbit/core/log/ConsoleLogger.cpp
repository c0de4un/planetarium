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
#ifndef ORBIT_CORE_CONSOLE_LOGGER_HPP
#include <orbit/core/log/ConsoleLogger.hpp>
#endif /// !ORBIT_CORE_CONSOLE_LOGGER_HPP

// Include STL iostream
#include <iostream>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ConsoleLogger
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        ConsoleLogger::ConsoleLogger()           = default;
        ConsoleLogger::~ConsoleLogger() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.ILogger
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void ConsoleLogger::printInfo(const char* const msg) noexcept
        {
            std::cout << "INFO: " << msg << "\n";
        }

        void ConsoleLogger::printDebug(const char* const msg) noexcept
        {
            std::cout << "DEBUG: " << msg << "\n";
        }

        void ConsoleLogger::printWarning(const char* const msg) noexcept
        {
            std::cout << "WARNING: " << msg << "\n";
        }

        void ConsoleLogger::printError(const char* const msg) noexcept
        {
            std::cout << "ERROR: " << msg << "\n";
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
