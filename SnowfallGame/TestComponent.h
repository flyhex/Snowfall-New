#pragma once
#include <ECS.h>

class TestComponent : public Component
{
};

class TestSystem : public ISystem
{
public:
	virtual void InitializeSystem(Scene & scene) override;
	virtual void Update(float deltaTime) override;
	virtual std::string GetName() override;
	virtual std::vector<std::string> GetSystemsBefore() override;
	virtual std::vector<std::string> GetSystemsAfter() override;
	virtual bool IsMainThread() override;
private:
	Scene *m_scene;
};