//快排
public static void quickSort(int[] array, int begin, int end){
	if (end <= begin) return;
	int pivot = partition(array, begin, end);
	quickSort(array, begin, pivot - 1);
	quickSort(array, pivot + 1, end);
}

static int partition(int[] a, int begin, int end){
	//pivot: 标杆位置， counter：小于pivot的元素的个数
	int pivot = end, counter = begin;
	for (int i = begin; i < end; i++){
		if(a[i] < a[pivot]){
			int temp = a[counter]; a[counter] = a[i]; a[i] = temp;
			counter++;
		}
	}
	int temp = a[pivot]; a[pivot] = a[counter]; a[counter] =temp;
	return counter;
}

//归并排序
public static void mergeSort(int[] array, int left, int right){
	if(right <= left) return;
	int mid = (left + right) >> 1;

	mergeSort(array, left, mid);
	mergeSort(array, mid + 1, right);
	merge(array, left, mid, right);
}
public static void merge(int[] arr, int left, int mid, int right){
	int[] temp = new int[right - left + 1];
	int i = left, j = mid +1, k = 0;
	while(i <= mid && j <= right){
		temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
	}
	while(i <= mid) temp[k++] = arr[i++];
	while(j <= right) temp[k++] = arr[j++];

	for(int p = 0; p < temp.length; p++){
		arr[left + p] = temp[p];
	}
	//也可以用 System.arraycopy(a, start1, b, start2, length)
}

//堆排序
void heap_sort(int a[], int len){
	priority_queue < int, vector<int>, greater<int> > q;

	for(int i = 0; i < len; i++){
		q.push(a[i]);
	}

	for(int i = 0; i < len; i++){
		a[i] = q.pop();
	}
}
