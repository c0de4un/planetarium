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
#ifndef ORBIT_CORE_ASSET_HPP
#include <orbit/core/assets/Asset.hpp>
#endif /// !ORBIT_CORE_ASSET_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Asset
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Asset::Asset()
            :
            mUsersCounter(0),
            mState(EAssetStates::ASSET_STATE_NONE)
        {
        }

        Asset::~Asset() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        size_t Asset::getUsers() const noexcept
        {
            return mUsersCounter;
        }

        bool Asset::isLoaded() const noexcept
        {
            return mState > EAssetStates::ASSET_STATE_NONE;
        }

        bool Asset::isLoading() const noexcept
        {
            return mState == EAssetStates::ASSET_STATE_LOADING;
        }

        bool Asset::isUnloading() const noexcept
        {
            return mState == EAssetStates::ASSET_STATE_UNLOADING;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.Asset
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool Asset::onLoad()
        {
            mState = EAssetStates::ASSET_STATE_LOADED;

            return true;
        }

        void Asset::onUnload()
        {
            mState = EAssetStates::ASSET_STATE_NONE;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.IAsset
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void Asset::addUser() noexcept
        {
            mUsersCounter++;
        }

        void Asset::removeUser() noexcept
        {
            mUsersCounter--;
        }

        bool Asset::Load()
        {
            if (isLoaded() || isLoading())
                return true;

            mState = EAssetStates::ASSET_STATE_LOADING;

            return true;
        }

        void Asset::Unload(const bool force)
        {
            if (!isLoaded() || isUnloading())
                return;

            mState = EAssetStates::ASSET_STATE_UNLOADING;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
