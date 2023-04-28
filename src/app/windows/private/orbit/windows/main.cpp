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
    // Initialize WinGraphics
    orbit_Graphics::Initialize(std::static_pointer_cast<orbit_WinGraphics, orbit_Graphics>( std::make_shared<orbit_WinGraphics>() ));
}

void Stop()
{
    orbit_Graphics::Terminate();
}

int main()
{
    std::cout << "Hello World !\n\n Press any key to exit . . .\n\n";
    std::cin.get();

    Start();
    Stop();

    return ORBIT_OK;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
