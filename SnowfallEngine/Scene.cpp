#include "Scene.h"
#include "Snowfall.h"

Scene::Scene()
{
	m_evManager = new EventManager;
	m_cManager = new ComponentManager(*this);
	m_eManager = new EntityManager(*this);
	m_sManager = new SystemManager(*this);
}

Scene::~Scene()
{
	delete m_evManager;
	delete m_cManager;
	delete m_eManager;
	delete m_sManager;
}

void Scene::Update(float deltaTime)
{
	m_sManager->UpdateSystems(deltaTime);
	m_cManager->CleanDeadComponents();
}