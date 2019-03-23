#include <Windows.h>

int main()
{
	STARTUPINFO si = {};
	SECURITY_ATTRIBUTES saProcess, saThread;
	PROCESS_INFORMATION piProcessB, piProcessC;

	saProcess.nLength = sizeof(saProcess);
	saProcess.lpSecurityDescriptor = NULL;
	saProcess.bInheritHandle = TRUE;

	saThread.nLength = sizeof(saThread);
	saThread.lpSecurityDescriptor = NULL;
	saThread.bInheritHandle = FALSE;

	TCHAR szPathB[MAX_PATH];
	ua_tcscpy_s(szPathB, MAX_PATH * sizeof(TCHAR), TEXT("ProcessB"));
	CreateProcess(
		NULL,
		szPathB,
		&saProcess,
		&saThread,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&piProcessB);

	TCHAR szPathC[MAX_PATH];
	ua_tcscpy_s(szPathC, MAX_PATH * sizeof(TCHAR), TEXT("ProcessC"));
	CreateProcess(
		NULL,
		szPathC,
		NULL,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&si,
		&piProcessC);
}
