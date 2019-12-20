int settingsMenu(){
	printSettingsMenu();
	switch(getChoice(0,3)){
		
	}
	return 1;
}

int analysisMenu(){
	printAnalysisMenu();
	return 1;
}

int checkingMenu(){
	printCheckingMenu();
	return 1;
}

int menu(){
	printMenu();
	switch(getChoice(0,4)){
		case 1:
			changeArea();
			break; 
		case 2:
			while(checkingMenu());
			break;
		case 3:
			while(analysisMenu());
			break;
		case 4:
			while(settingsMenu());
			break;
		default:
			return 0;
	}
	return 1;
}

