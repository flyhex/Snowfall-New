#include <Windows.h>

#include <Snowfall.h>


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	EngineSettings settings;

	settings.TextureUnits = 84;
	settings.ImageUnits = 32;
	settings.MaxMeshMemoryBytes = 8e8;
	settings.MaxTerrainMemoryBytes = 2e8;
	settings.MaxMeshCommands = 2e5;
	settings.ShadowMapResolution = 2048;
	settings.CloseShadowMapResolution = 2048;
	settings.MaxWorkerThreads = std::thread::hardware_concurrency() / 2;
	settings.MaxTextureMemoryBytes = 5e9;

	Snowfall::InitGlobalInstance(settings);

	Snowfall::GetGameInstance().GetAssetManager().SetUserDataFolder("Snowfall");
	Snowfall::GetGameInstance().GetAssetManager().EnumerateUnpackedFolder(".\\Assets");
	Snowfall::GetGameInstance().LoadModules({ "SnowfallGame.dll" });
	
	Snowfall::GetGameInstance().StartGame();

	return 0;
}

