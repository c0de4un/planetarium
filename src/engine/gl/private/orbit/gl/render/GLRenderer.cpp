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
#ifndef ORBIT_GL_RENDERER_HPP
#include <orbit/gl/render/GLRenderer.hpp>
#endif /// !ORBIT_GL_RENDERER_HPP

// Include orbit::core::Material
#ifndef ORBIT_CORE_MATERIAL_HPP
#include <orbit/core/assets/materials/Material.hpp>
#endif /// !ORBIT_CORE_MATERIAL_HPP

// Include orbit::gl::Sphere
#ifndef ORBIT_GL_SPHERE_HPP
#include <orbit/gl/assets/mesh/Sphere.hpp>
#endif /// !ORBIT_GL_SPHERE_HPP

// DEBUG
#ifdef ORBIT_DEBUG

// Include orbit::debug
#ifndef ORBIT_CORE_DEBUG_HPP
#include <orbit/core/cfg/orbit_debug.hpp>
#endif /// !ORBIT_CORE_DEBUG_HPP

#endif
// DEBUG
 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// GLRenderer
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace orbit
{

    namespace gl
    {

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // CONSTRUCTOR & DESTRUCTOR
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        GLRenderer::GLRenderer()
            :
            RenderSystem(),
            mFirstFrame(true)
        {
        }

        GLRenderer::~GLRenderer() noexcept = default;

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.System
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        bool GLRenderer::onStart()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("GLRenderer::onStart");
#endif // DEBUG

            return System::onStart();
        }

        bool GLRenderer::onResume()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("GLRenderer::onResume");
#endif // DEBUG

            return System::onResume();
        }

        bool GLRenderer::onPause()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("GLRenderer::onPause");
#endif // DEBUG

            return System::onPause();
        }

        void GLRenderer::onStop()
        {
#ifdef ORBIT_DEBUG // DEBUG
            orbit_Log::info("GLRenderer::onStop");
#endif // DEBUG

            System::onStop();
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.IMeshFactory
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        std::shared_ptr<orbit_IMesh> GLRenderer::createSphere3D()
        {
            return std::static_pointer_cast<orbit_IMesh, orbit_Sphere>( std::make_shared<orbit_Sphere>(10.0f, 36, 18) );
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.IRenderer
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        std::shared_ptr<orbit_Material> GLRenderer::createMaterial()
        {
            return std::make_shared<orbit_Material>();
        }

        std::shared_ptr<orbit_Shader> GLRenderer::createShader(const unsigned char shaderType, const std::string sourceFile)
        {
            // @TODO: GLRenderer::createShader()
            return std::shared_ptr<orbit_Shader>(nullptr);
        }

        std::shared_ptr<orbit_Batch> GLRenderer::addDrawable(std::shared_ptr<orbit_BatchRequest> pRequest)
        {
            //orbit_BatchRequest* const request(pRequest.get());
            //GLBatch batch{
            //    std::mutex(), // mMutex
            //    false,        // mDisabled
            //    request->mTransparent,
            //};

            // @TODO: GLRenderer::addDrawable()
            return std::shared_ptr<orbit_Batch>(nullptr);
        }

        void GLRenderer::removeDrawable(std::shared_ptr<orbit_Batch> pBatch)
        {
            // @TODO: GLRenderer::removeDrawable()
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // METHODS.GLRenderer
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        void GLRenderer::Draw()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            size_t listenerIndex(0);
            std::shared_ptr<orbit_IRenderListener> listener(nullptr);

            // First Frame
            if (mFirstFrame)
            {
                mFirstFrame = false;

                while (listener = getNextListener(listenerIndex))
                {
                    if (!isStarted())
                        return;

                    listener->onFirstFrame();

                    listenerIndex++;
                }
            }

            // Allow Listeners to handle render-thread
            listenerIndex = 0;
            listener = nullptr;
            while (listener = getNextListener(listenerIndex))
            {
                if (!isStarted())
                    return;

                listener->onRender();

                listenerIndex++;
            }
        }

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
