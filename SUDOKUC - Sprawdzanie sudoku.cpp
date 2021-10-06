#include <iostream>

using namespace std;
bool check(int[][9]);
bool checkBy9Loops(int[][9]);
bool checkByLessLoops(int[][9]);

int main()
{
	int a = 0;
	bool original1 = true, original2 = true;
	int  number = 0;

	int sudoku[9][9] = { {0} };


	cin >> a;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				cin >> number;
				sudoku[j][k] = number;
			}
		}

		original1 = check(sudoku);
		//original2 = checkBy9Loops(sudoku);
		original2 = checkByLessLoops(sudoku);
		if (original1 && original2)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}





}

bool check(int sudoku[][9]) {

	int check[9] = { 0 };
	bool firstCheck = true;
	bool secondCheck = true;
	bool thirdCheck = true;


	// 1. sprawdzenie - wierszami
	for (int i = 0; i < 9; i++) {
		if (!firstCheck) {
			//cout << "Petla z i: Przerywam, bo firstCheck jest false" << endl;
			break;
		}
		for (int j = 0; j < 9; j++) {
			check[j] = sudoku[i][j];
			if (j > 0) {
				for (int k = 0; k < j; k++) {
					if (check[k] == check[j]) {
						//cout << "Powtarza sie cyfra" << check[k] << endl;
						firstCheck = false;
						break;
					}


				}
			}
			if (!firstCheck) {
				//cout << "Petla z j: Przerywam, bo firstCheck jest false" << endl;
				break;
			}

		}
	}

	//2. sprawdzenie - kolumnami

	for (int i = 0; i < 9; i++) {
		if (!secondCheck) {
			//cout << "Petla z i: Przerywam, bo firstCheck jest false" << endl;
			break;
		}
		for (int j = 0; j < 9; j++) {
			check[j] = sudoku[j][i];
			if (j > 0) {
				for (int k = 0; k < j; k++) {
					if (check[k] == check[j]) {
						//cout << "Powtarza sie cyfra" << check[k] << endl;
						secondCheck = false;
						break;
					}


				}
			}
			if (!secondCheck) {
				//cout << "Petla z j: Przerywam, bo firstCheck jest false" << endl;
				break;
			}

		}
	}

	//3. sprawdzenie - wartosci liczbowe
	for (int i = 0; i < 9; i++) {
		if (!thirdCheck) {
			//cout << "Petla z i: Przerywam bo trzeci warunek" << endl;
			break;
		}
		for (int j = 0; j < 9; j++) {
			if (!(sudoku[i][j] > 0 && sudoku[i][j] < 10)) {
				thirdCheck = false;
				//cout << "Petla z j: Przerywam bo trzeci warunek" << endl;
				break;
			}

		}
	}

	if (firstCheck && secondCheck && thirdCheck)
		return true;
	else
		return false;
}

bool checkBy9Loops(int sudoku[][9]) {

	int tabChecking[9] = { 0 };
	int count = 0;
	bool original = true;

	//cout << endl << endl;

	for (int i = 0; i < 3; i++) {
		if (!original)
			break;
		for (int j = 0; j < 3; j++) {
			if (!original)
				break;

			if (count == 0) {
				tabChecking[0] = sudoku[i][j];
				//cout << tabChecking[0] << " ";
				count++;
			}
			else {
				for (int k = 0; k < count; k++) {
					if (tabChecking[k] == sudoku[i][j]) {
						/*cout << "k: " << k << endl;
						cout << "tabchecking[k]: " << tabChecking[k] << endl;
						cout << "sudoku [i][j]" << sudoku[i][j] << endl;
						cout << "i: " << i << " j: " << j << endl;
						cout << "count : " << count << endl;
						cout << "!!!" << tabChecking[k] << "!!!" << endl;*/
						original = false;
						break;
					}

				}
				if (original) {
					tabChecking[count] = sudoku[i][j];
					//cout << tabChecking[count] << " ";
					count++;
				}
			}
		}
	}
	count = 0;
	//cout << "-----------------------------------------" << endl;
	for (int i = 0; i < 3; i++) {
		if (!original)
			break;
		for (int j = 3; j < 6; j++) {
			if (!original)
				break;

			if (count == 0) {
				tabChecking[0] = sudoku[i][j];
				//cout << tabChecking[0] << " ";
				count++;
			}
			else {
				for (int k = 0; k < count; k++) {
					if (tabChecking[k] == sudoku[i][j]) {
						original = false;
						break;
					}
				}
				if (original) {
					tabChecking[count] = sudoku[i][j];
					//cout << tabChecking[count] << " ";
					count++;
				}
			}
		}
	}
	//cout << "-----------------------------------------" << endl;
	count = 0;
	for (int i = 0; i < 3; i++) {
		if (!original)
			break;
		for (int j = 6; j < 9; j++) {
			if (!original)
				break;

			if (count == 0) {
				tabChecking[0] = sudoku[i][j];
				//cout << tabChecking[0] << " ";
				count++;
			}
			else {
				for (int k = 0; k < count; k++) {
					if (tabChecking[k] == sudoku[i][j]) {
						original = false;
						break;
					}
				}
				if (original) {
					tabChecking[count] = sudoku[i][j];
					//cout << tabChecking[count] << " ";
					count++;
				}
			}
		}
	}
	//cout << "-----------------------------------------" << endl;
	count = 0;
	for (int i = 3; i < 6; i++) {
		if (!original)
			break;
		for (int j = 0; j < 3; j++) {
			if (!original)
				break;

			if (count == 0) {
				tabChecking[0] = sudoku[i][j];
				//cout << tabChecking[0] << " ";
				count++;
			}
			else {
				for (int k = 0; k < count; k++) {
					if (tabChecking[k] == sudoku[i][j]) {
						original = false;
						break;
					}

				}
				if (original) {
					tabChecking[count] = sudoku[i][j];
					//cout << tabChecking[count] << " ";
					count++;
				}
			}
		}
	}
	//cout << "-----------------------------------------" << endl;
	count = 0;
	for (int i = 3; i < 6; i++) {
		if (!original)
			break;
		for (int j = 3; j < 6; j++) {
			if (!original)
				break;

			if (count == 0) {
				tabChecking[0] = sudoku[i][j];
				//cout << tabChecking[0] << " ";
				count++;
			}
			else {
				for (int k = 0; k < count; k++) {
					if (tabChecking[k] == sudoku[i][j]) {
						original = false;
						break;
					}

				}
				if (original) {
					tabChecking[count] = sudoku[i][j];
					//cout << tabChecking[count] << " ";
					count++;
				}
			}
		}
	}
	//cout << "-----------------------------------------" << endl;
	count = 0;
	for (int i = 3; i < 6; i++) {
		if (!original)
			break;
		for (int j = 6; j < 9; j++) {
			if (!original)
				break;

			if (count == 0) {
				tabChecking[0] = sudoku[i][j];
				//cout << tabChecking[0] << " ";
				count++;
			}
			else {
				for (int k = 0; k < count; k++) {
					if (tabChecking[k] == sudoku[i][j]) {
						original = false;
						break;
					}
				}
				if (original) {
					tabChecking[count] = sudoku[i][j];
					//cout << tabChecking[count] << " ";
					count++;
				}
			}
		}
	}
	//cout << "-----------------------------------------" << endl;
	count = 0;
	for (int i = 6; i < 9; i++) {
		if (!original)
			break;
		for (int j = 0; j < 3; j++) {
			if (!original)
				break;

			if (count == 0) {
				tabChecking[0] = sudoku[i][j];
				//cout << tabChecking[0] << " ";
				count++;
			}
			else {
				for (int k = 0; k < count; k++) {
					if (tabChecking[k] == sudoku[i][j]) {
						original = false;
						break;
					}

				}
				if (original) {
					tabChecking[count] = sudoku[i][j];
					//cout << tabChecking[count] << " ";
					count++;
				}
			}
		}
	}
	//cout << "-----------------------------------------" << endl;
	count = 0;
	for (int i = 6; i < 9; i++) {
		if (!original)
			break;
		for (int j = 3; j < 6; j++) {
			if (!original)
				break;

			if (count == 0) {
				tabChecking[0] = sudoku[i][j];
				//cout << tabChecking[0] << " ";
				count++;
			}
			else {
				for (int k = 0; k < count; k++) {
					if (tabChecking[k] == sudoku[i][j]) {
						original = false;
						break;
					}

				}
				if (original) {
					tabChecking[count] = sudoku[i][j];
					//cout << tabChecking[count] << " ";
					count++;
				}
			}
		}
	}
	//cout << "-----------------------------------------" << endl;
	count = 0;
	for (int i = 6; i < 9; i++) {
		if (!original)
			break;
		for (int j = 6; j < 9; j++) {
			if (!original)
				break;

			if (count == 0) {
				tabChecking[0] = sudoku[i][j];
				//cout << tabChecking[0] << " ";
				count++;
			}
			else {
				for (int k = 0; k < count; k++) {
					if (tabChecking[k] == sudoku[i][j]) {
						original = false;
						break;
					}

				}
				if (original) {
					tabChecking[count] = sudoku[i][j];
					//cout << tabChecking[count] << " ";
					count++;
				}
			}
		}
	}
	if (original)
		return true;
	return false;
}

bool checkByLessLoops(int sudoku[][9]) {

	int tabChecking[9] = { 0 };
	bool original = true;
	int count = 0;

	for (int c = 0; c < 9; c++) {
		if (!original)
			break;
		else {
			count = 0;
			if (c < 3) {
				for (int i = 0; i < 3; i++) {
					if (!original)
						break;
					if (c % 3 == 0) {
						for (int j = 0; j < 3; j++) {
							if (!original)
								break;
							if (count == 0) {
								tabChecking[0] = sudoku[i][j];
								count++;
							}
							else
							{
								for (int k = 0; k < count; k++) {
									if (tabChecking[k] == sudoku[i][j]) {
										original = false;
										break;
									}
								}
								if (original) {
									tabChecking[count] = sudoku[i][j];
									count++;
								}

							}
						}
					}
					else if (c % 3 == 1) {
						for (int j = 3; j < 6; j++) {
							if (!original)
								break;
							if (count == 0) {
								tabChecking[0] = sudoku[i][j];
								count++;
							}
							else
							{
								for (int k = 0; k < count; k++) {
									if (tabChecking[k] == sudoku[i][j]) {
										original = false;
										break;
									}
								}
								if (original) {
									tabChecking[count] = sudoku[i][j];
									count++;
								}

							}
						}
					}
					else {
						for (int j = 6; j < 9; j++) {
							if (!original)
								break;
							if (count == 0) {
								tabChecking[0] = sudoku[i][j];
								count++;
							}
							else
							{
								for (int k = 0; k < count; k++) {
									if (tabChecking[k] == sudoku[i][j]) {
										original = false;
										break;
									}
								}
								if (original) {
									tabChecking[count] = sudoku[i][j];
									count++;
								}

							}
						}
					}
				}
			}
			else if (c < 6) {
				for (int i = 3; i < 6; i++) {
					if (c % 3 == 0) {
						for (int j = 0; j < 3; j++) {
							if (!original)
								break;
							if (count == 0) {
								tabChecking[0] = sudoku[i][j];
								count++;
							}
							else
							{
								for (int k = 0; k < count; k++) {
									if (tabChecking[k] == sudoku[i][j]) {
										original = false;
										break;
									}
								}
								if (original) {
									tabChecking[count] = sudoku[i][j];
									count++;
								}

							}
						}
					}
					else if (c % 3 == 1) {
						for (int j = 3; j < 6; j++) {
							if (!original)
								break;
							if (count == 0) {
								tabChecking[0] = sudoku[i][j];
								count++;
							}
							else
							{
								for (int k = 0; k < count; k++) {
									if (tabChecking[k] == sudoku[i][j]) {
										original = false;
										break;
									}
								}
								if (original) {
									tabChecking[count] = sudoku[i][j];
									count++;
								}

							}
						}
					}
					else {
						for (int j = 6; j < 9; j++) {
							if (!original)
								break;
							if (count == 0) {
								tabChecking[0] = sudoku[i][j];
								count++;
							}
							else
							{
								for (int k = 0; k < count; k++) {
									if (tabChecking[k] == sudoku[i][j]) {
										original = false;
										break;
									}
								}
								if (original) {
									tabChecking[count] = sudoku[i][j];
									count++;
								}

							}
						}
					}
				}
			}
			else {
				for (int i = 6; i < 9; i++) {
					if (c % 3 == 0) {
						for (int j = 0; j < 3; j++) {
							if (!original)
								break;
							if (count == 0) {
								tabChecking[0] = sudoku[i][j];
								count++;
							}
							else
							{
								for (int k = 0; k < count; k++) {
									if (tabChecking[k] == sudoku[i][j]) {
										original = false;
										break;
									}
								}
								if (original) {
									tabChecking[count] = sudoku[i][j];
									count++;
								}

							}
						}
					}
					else if (c % 3 == 1) {
						for (int j = 3; j < 6; j++) {
							if (!original)
								break;
							if (count == 0) {
								tabChecking[0] = sudoku[i][j];
								count++;
							}
							else
							{
								for (int k = 0; k < count; k++) {
									if (tabChecking[k] == sudoku[i][j]) {
										original = false;
										break;
									}
								}
								if (original) {
									tabChecking[count] = sudoku[i][j];
									count++;
								}

							}
						}
					}
					else {
						for (int j = 6; j < 9; j++) {
							if (!original)
								break;
							if (count == 0) {
								tabChecking[0] = sudoku[i][j];
								count++;
							}
							else
							{
								for (int k = 0; k < count; k++) {
									if (tabChecking[k] == sudoku[i][j]) {
										original = false;
										break;
									}
								}
								if (original) {
									tabChecking[count] = sudoku[i][j];
									count++;
								}

							}
						}
					}
				}
			}
		}

	}
	if (original)
		return true;
	return false;
}