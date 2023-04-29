/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#pragma once

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ALIASES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static constexpr const int ORBIT_OK = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include orbit::windows::WinGraphics
#ifndef ORBIT_WIN_GRAPHICS_HPP
#include <orbit/windows/graphics/WinGraphics.hpp>
#endif /// !ORBIT_WIN_GRAPHICS_HPP

// DEBUG
#ifdef ORBIT_DEBUG

// Include orbit::debug
#ifndef ORBIT_CORE_DEBUG_HPP
#include <orbit/core/cfg/orbit_debug.hpp>
#endif /// !ORBIT_CORE_DEBUG_HPP

// Include orbit::core::ConsoleLogger
#ifndef ORBIT_CORE_CONSOLE_LOGGER_HPP
#include <orbit/core/log/ConsoleLogger.hpp>
#endif /// !ORBIT_CORE_CONSOLE_LOGGER_HPP

#endif
// DEBUG

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
