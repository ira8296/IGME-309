#include "AppClass.h"
void Application::InitVariables(void)
{
	//init the mesh
	m_pMesh = new MyMesh();
	//m_pMesh->GenerateCube(1.0f, C_WHITE);
	m_pMesh->GenerateCube(1.0f, C_BLACK);
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	
	matrix4 m4Scale = glm::scale(IDENTITY_M4, vector3(2.0f,2.0f,2.0f));
	static float value = 0.0f;
	matrix4 m4Translate = glm::translate(IDENTITY_M4, vector3(value, 2.0f, 3.0f));
	value += 0.01f;

	//matrix4 m4Model = m4Translate * m4Scale;
	matrix4 m4Model = m4Scale * m4Translate;


	matrix4 pixelTranslate;
	
	int interval; 

	for (int i = -5; i <= 5; i++)
	{
		pixelTranslate= glm::translate(IDENTITY_M4, vector3(i, 0, 0));
		interval = i;
		m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
	}

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(5, -1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-5, -1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-3, -1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	for (int n = -3; n <= 3; n++) {
		pixelTranslate = glm::translate(IDENTITY_M4, vector3(n, -1, 0));
		m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
	}

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(3, -2, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(5, -2, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-3, -2, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-5, -2, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-2, -3, 0));
	for (int i = -2; i < 0; i++) {
		m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
		pixelTranslate = glm::translate(IDENTITY_M4, vector3(i, -3, 0));
	}

	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(1, -3, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
	pixelTranslate = glm::translate(IDENTITY_M4, vector3(2, -3, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(4, 1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
	pixelTranslate = glm::translate(IDENTITY_M4, vector3(3, 1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(1, 1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
	pixelTranslate = glm::translate(IDENTITY_M4, vector3(0, 1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-1, 1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-3, 1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-4, 1, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-2, 2, 0));

	for (int x = -3; x <= 4; x++) {
		m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
		pixelTranslate = glm::translate(IDENTITY_M4, vector3(x, 2, 0));
	}

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(2, 3, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-2, 3, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);

	pixelTranslate = glm::translate(IDENTITY_M4, vector3(3, 4, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);
	pixelTranslate = glm::translate(IDENTITY_M4, vector3(-3, 4, 0));
	m_pMesh->Render(m4Projection, m4View, m4Model * pixelTranslate);


	
	
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	SafeDelete(m_pMesh);

	//release GUI
	ShutdownGUI();
}