// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int couple = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (((*(arr + i)) + (*(arr + j))) == value) {
				couple += 1;
			}
		}
	}
	return couple;
}
int countPairs2(int *arr, int len, int value) {
    int couple = 0;
	for (int i = 0; i < len; i++) {
		for (int j = len - 1; j > i; j--) {
			if (((*(arr + i)) + (*(arr + j))) == value) {
				couple += 1;
			}
		}
	}
    return couple;
}
int countPairs3(int *arr, int len, int value) {
    int couple = 0;
	int mid = 0;
	int left = 0, right = 0;
	for (int i = 0; i < len - 1; i++) {
		left = i;
		right = len;
		while (left < right - 1) {
			mid = (left + right) / 2;
			if (*(arr + i) + *(arr + mid) == value) {
				couple += 1;
				int j = mid + 1;
				while ((*(arr + i) + *(arr + j) == value) && (j < right)) {
					couple += 1;
					j++;
				}
				j = mid - 1;
				while (((*(arr + i) + *(arr + j) == value) && (j > left))) {
					couple += 1;
					j--;
				}
				break;
			}
			if (*(arr + i) + *(arr + mid) > value)
				right = mid;
			else
				left = mid;
		}
	}
	return couple;
}
