#include"AirBypass2.h"

AirWindow BW;
AirMemory AM, HM;

bool bAutoClose = true;

void AirBypass(){
	Bypass();
	HackShieldBypass();
	Sleep(5000);
	if(bAutoClose){
		BW.UnInit();
	}
}

void BWCreate(HWND hWnd){
	BW.EditBox(EDIT_LOG, "AirBypass by �����~�g\r\nfor JMS and HS v5.6.34.449\r\n", 3,3, 394, 20);
	BW.ReadOnly(EDIT_LOG);
	BW.CheckBox(CHECK_AC, "�����I��", 3, 250, true);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)AirBypass, NULL ,NULL, NULL);
}

void BWControl(WORD wID){
	switch(wID){
	case CHECK_AC:
		bAutoClose = BW.CheckBoxStatus(wID);
		break;

	default:
		break;
	}
}

void AirBypass2_Run(HINSTANCE hinstDLL){
	BW.Init(hinstDLL, "AirBypass", 400, 300, true, BWCreate, BWControl);
}