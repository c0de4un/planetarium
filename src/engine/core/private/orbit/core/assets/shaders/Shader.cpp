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
#ifndef ORBIT_CORE_SHADER_HPP
#include <orbit/core/assets/shaders/Shader.hpp>
#endif /// !ORBIT_CORE_SHADER_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Shader
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace core
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        Shader::Shader(const unsigned char shaderType, const std::string sourceFile)
            :
            Asset(),
            mMaterialSlotType(getMaterialSlotType(shaderType)),
            mShaderType(shaderType),
            mSourceFile(sourceFile) // Copy
        {
        }

        Shader::~Shader() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // GETTERS & SETTERS
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        unsigned char Shader::getMaterialSlotType(const unsigned shaderType) noexcept
        {
            switch (shaderType)
            {
                case orbit_EShaderTypes::SHADER_TYPE_VERTEX:
                    return orbit_EMaterialSlots::MATERIAL_SLOT_VERTEX_SHADER;

                case orbit_EShaderTypes::SHADER_TYPE_FRAGMENT:
                    return orbit_EMaterialSlots::MATERIAL_SLOT_FRAGMENT_SHADER;

                case orbit_EShaderTypes::SHADER_TYPE_GEOMETRY:
                    return orbit_EMaterialSlots::MATERIAL_SLOT_GEOMETRY_SHADER;
            }

            return orbit_EMaterialSlots::MATERIAL_SLOT_VERTEX_SHADER;
        }

        unsigned char Shader::getShaderType() const noexcept
        {
            return mShaderType;
        }

        unsigned char Shader::getSlotType() const noexcept
        {
            return mMaterialSlotType;
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
