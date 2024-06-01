// Copyright ❤️ 2023-2024, Sergei Belov

#include "Components/ComponentGroup.h"
#include "Components/EventLoopComponent.h"
#include "Components/FrameRateComponent.h"
#include "Components/IMGUIComponent.h"
#include "Components/LocalizationComponent.h"
#include "Components/SDLEventComponent.h"
#include "Components/SDLWindowComponent.h"
#include "Components/SettingsComponent.h"
#include "Components/ViewComponent.h"
#include "Components/WindowTitleComponent.h"

int main(int argc, char* argv[]) {
	if (!std::filesystem::exists("README.md")) {
		std::filesystem::current_path(SDL_GetBasePath());
	}

	// clang-format off
	std::ignore = ComponentGroup<
		EventLoopComponent,
		SDLEventComponent,
		SDLWindowComponent,
		IMGUIComponent,
		SettingsComponent,
		LocalizationComponent,
		ViewComponent,
		WindowTitleComponent,
		FrameRateComponent
	>();
	// clang-format on

	Event<Application::Initialize>::Send();
	Event<Application::Launch>::Send();

	Application::Exit exitEvent;
	Event<Application::Exit>::Send(exitEvent);

	return exitEvent.exitCode;
}
