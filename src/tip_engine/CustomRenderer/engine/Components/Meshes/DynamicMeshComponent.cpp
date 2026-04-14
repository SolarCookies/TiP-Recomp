#include "DynamicMeshComponent.h"
#include "../../World/World.h"
#include "../Lights/LightComponent.h"

void DynamicMeshComponent::Construct()
{
	ReInitializeModel();
	//add owner transform to the model
	Mat = owner->GetTransform();
	Mat = glm::translate(Mat, Position);
	OBJ->SetMaterialParameter("model", Mat);

	
}

void DynamicMeshComponent::BeginPlay()
{

}

void DynamicMeshComponent::Tick(float deltaTime, World* World)
{
	if (World == nullptr)
		return;
	if(OBJ == nullptr)
		return;
	LightComponent* lightSource = World->GetLightSource();
	if (lightSource)
	{
		OBJ->SetMaterialParameter("lightColor", lightSource->lightColor);
		OBJ->SetMaterialParameter("lightPos", lightSource->lightPos);
	}
	else {
		OBJ->SetMaterialParameter("lightColor", glm::vec4(0));
		OBJ->SetMaterialParameter("lightPos", glm::vec3(0));
	}

	//update the model matrix with the current transform
	Mat = owner->GetTransform();
	Mat = glm::translate(Mat, Position);
	OBJ->SetMaterialParameter("model", Mat);

	if (ColorTexture.ID != 0)
	{
		//OBJ->SetMaterialParameter("tex0", ColorTexture);
	}
	if (NormalTexture.ID != 0)
	{
		//OBJ->SetMaterialParameter("tex1", NormalTexture);
	}
	
}

void DynamicMeshComponent::Render(VinceWindow* window, class Camera* Cam)
{
	//OBJ.model.SetMaterialParameter("unlit", unlit ? 1 : 0);
	//OBJ->SetMaterialParameter("unlit", 0);

	OBJ->SetMaterialParameter("cameraPos", Cam->Position);
	Cam->Matrix(*OBJ->material->shaderProgram.get(), "camMatrix");

	glActiveTexture(GL_TEXTURE0);
	ColorTexture.Bind();

	Draw(Cam->ShadowPerspective,window,Cam);
}

void DynamicMeshComponent::Draw(bool shadow, VinceWindow* window, class Camera* Cam)
{
	if (isTriangleStrip){
		//OBJ->Draw(true,0); //Skip this because it messes up oter meshes that are not triangle strips
		glEnable(GL_BLEND);
		glBlendEquation(GL_FUNC_ADD);
		OBJ->Draw(true, 0,shadow,window,Cam);
	}
	else {
		glEnable(GL_BLEND);
		glBlendEquation(GL_FUNC_ADD);
		OBJ->Draw(false,0,shadow,window,Cam);
	}
}
