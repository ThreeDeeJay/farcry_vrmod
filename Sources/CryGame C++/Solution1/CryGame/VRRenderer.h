#pragma once
#include "Cry_Camera.h"

class CXGame;
class IDirect3DDevice9Ex;

class VRRenderer
{
	typedef void (*SystemRenderFunc)(ISystem* system);

public:
	void Init(CXGame *game);
	void Shutdown();

	void Render(ISystem *pSystem);
	void OnPrePresent();
	void OnPostPresent();

	const CCamera& GetCurrentViewCamera() const;
	void ProjectToScreenPlayerCam(float ptx, float pty, float ptz, float* sx, float* sy, float* sz);

	void ChangeRenderResolution(int width, int height);

	bool ShouldRenderVR() const;
	bool ShouldRenderStereo() const;

	bool ShouldIgnoreWindowSizeChanges() const { return m_ignoreWindowSizeChanges; }

private:
	CXGame* m_pGame;
	CCamera m_originalViewCamera;
	bool m_viewCamOverridden = false;
	bool m_binocularsActive = false;
	bool m_ignoreWindowSizeChanges = false;

	void RenderSingleEye(int eye, ISystem* pSystem);
	void DrawCrosshair();
};

extern VRRenderer* gVRRenderer;
