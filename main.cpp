#include <windows.h>
constexpr int gapsize = 15;

void gaped_fullscreen(void){

  HWND currently_focusedwindow = GetForegroundWindow();
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
	// RegisterHotKey(nullptr, 1, MOD_WIN, 'G');
	// MSG msg;
	// while (GetMessage(&msg, nullptr, 0, 0)){
	// 	if (msg.message == WM_HOTKEY and msg.wParam==1) {
	// 		gaped_fullscreen();
	// 	}
	// }
	// gaped_fullscreen();
	UnregisterHotKey(nullptr,1);

  return 0;
}
