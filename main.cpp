#define WIN32_LEAN_AND_MEAN
#include <windows.h>
constexpr int gapsize = 15;

void gaped_fullscreen(void){

  HWND currently_focusedwindow = GetForegroundWindow();
  // HWND currently_focusedwindow = GetActiveWindow(); // what is this??
  if (!currently_focusedwindow){
	  return;
  }

  RECT work_area;
  // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa#:~:text=SPI%5FGETWORKAREA
  // only works in pirmary monitor To get the work area of a monitor other than
  // the primary display monitor, call the GetMonitorInfo function.
  SystemParametersInfo(SPI_GETWORKAREA, 0, &work_area, 0);

  int updated_topleftx = work_area.left + gapsize;
  int updated_toplefty = work_area.top + gapsize;
  //good to use work_area properties to make it taskbar agnostic
  int updated_windowwidth = work_area.right - work_area.left - 2*gapsize;
  int updated_windowlength = work_area.bottom - work_area.top - 2*gapsize;

  ShowWindow(currently_focusedwindow, SW_RESTORE);
  SetWindowPos(currently_focusedwindow, HWND_TOP, updated_topleftx, updated_toplefty, updated_windowwidth, updated_windowlength, SWP_FRAMECHANGED|SWP_SHOWWINDOW);
  // TODO i picked random flags for above function and it worked (so view them later)


}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nShowCmd) {
	//TODO refactor the logic
	while (true){
		if ((GetKeyState(VK_LWIN) || GetKeyState(VK_RWIN)) && GetKeyState('G')){
			gaped_fullscreen();
		}
	}

  return 0;
}
