#include<stdio.h>
#include <time.h>

int todayYMD, ticketSelect, idNumber, backIdNumber, orderCount, discount, age, generation, 
	price, countPrice, discountPrice, again, next;	
	
int todayYMDArr[10] = {0}, ticketSelectArr[10] = {0}, generationArr[10] = {0},	
	orderCountArr[10] = {0}, discountArr[10] = {0}, discountPriceArr[10] = {0};
	
int totalPrice = 0, index = 0;
int year, month, day;

// 파크입장권
const int ADULT_DAY = 56000, TEEN_DAY = 50000, CHILD_DAY = 46000, BABY_DAY = 15000, FREE = 0;
const int ADULT_AFTER = 45000, TEEN_AFTER = 40000, CHILD_AFTER = 35000, BABY_AFTER = 15000;
	
// 종합입장권 
const int ADULT_DAY_TOTAL = 59000, TEEN_DAY_TOTAL = 52000, CHILD_DAY_TOTAL = 47000, BABY_DAY_TOTAL = 15000;
const int ADULT_AFTER_TOTAL = 48000, TEEN_AFTER_TOTAL = 42000, CHILD_AFTER_TOTAL = 36000, BABY_AFTER_TOTAL = 15000;

// 오늘 날짜 계산
void todayDate(){
	struct tm *today;
	time_t timer;
	time(&timer);
	today = localtime(&timer); 
	timer = time(NULL); 
	year = (today -> tm_year -100)*10000;
	month = (today -> tm_mon +1)*100;
	day = today -> tm_mday;
	todayYMD = year + month + day;
}

// 권종 선택 
void inputTicketSelect(){
	do{  
		printf(" 권종을 선택하세요.(After4는 오후 4시부터 입장)");
		printf("\n 1. 파크이용권 [1DAY]\n 2. 파크이용권 [After4]\n 3. 종합이용권 [1DAY]\n 4. 종합이용권 [After4]\n\t");
		scanf("%d", &ticketSelect);
		
		if(!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 )){
			printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
			}
			
	}while (!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 ));
} 

// 주민번호앞자리 입력
void inputIdNumber(){
	do{ 
		printf("\n 주민번호 앞 6글자를 입력하세요\n\t");
		scanf("%d", &idNumber);
		
		if(!((idNumber >= 000101) && (idNumber <= 991231))){
			printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
			}
			
	}while (!((idNumber >= 000101) && (idNumber <= 991231)));
} 

// 주민번호 뒷자리 입력
void inputBackIdNumber(){
	do{ 
		printf("\n 주민번호 뒤 1글자를 입력하세요\n\t");
		scanf("%d", &backIdNumber);
		if(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 )){
			printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
			}
			
	}while(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 ));
} 

// 갯수 입력
void inputOrderCount(){
	do{
		printf("\n 몇개를 주문하시겠습니까? (최대 10개) \n\t");
		scanf("%d", &orderCount);
		if(orderCount > 10){
				printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
			}
			
	}while(orderCount > 10);
} 

// 우대사항 입력
void inputDiscount(){
	do{
		printf("\n 우대사항을 선택하세요. \n 1. 없음(나이 우대는 자동처리)\n 2. 장애인 \n 3. 국가유공자 \n 4. 휴가장병 \n 5. 임산부\n 6. 다둥이\n\t");
		scanf("%d", &discount);
		if(!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6)){
			printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
		}
		
	}while (!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6));
} 

// 만나이 계산
void ageCalculation(){
	age = (todayYMD - (idNumber))/10000;	
	if((backIdNumber == 1) || (backIdNumber == 2)){
		age = age + 100;
	}
} 

// 연령구분
void ageGeneration(){
	if(age < 1){							// 0 ~ 12개월 => 1 
		generation = 1;									 
	}	 
	else if((age >= 1) && (age < 3)){		// 12개월이상 36개월 미만 => 2
		generation = 2;	
	}
	else if((age >= 3) && (age < 13)){		// 36개월이상 만 12세 미만 => 3
		generation = 3;
	}
	else if((age >= 13) && (age < 18)){		// 만 12세 이상 18세 미만 => 4
		generation = 4;
	}
	else if((age >= 19) && (age < 65)){		// 만 18세 이상 65세 미만  => 5
		generation = 5;
	}
	else if(age >= 65){						// 만 65세 이상 => 6
		generation = 6;
	}
} 

// 나이별 가격측정
void generationPrice(){
	switch(ticketSelect){
		case 1 : 
			if(generation == 1){
				price = FREE;
			} 
			else if(generation == 2){
				price = BABY_DAY;
				}
			else if(generation == 3){
				price = CHILD_DAY;
				}
			else if(generation == 4){
				price = TEEN_DAY;
				}
			else if(generation == 5){
				price = ADULT_DAY;
				}
			else if(generation == 6){
				price = CHILD_DAY;
				} 
			break;
			
		case 2 :
			if(generation == 1){
				price = FREE;
			} 
			else if(generation == 2){
				price = BABY_AFTER;
				}
			else if(generation == 3){
				price = CHILD_AFTER;
				}
			else if(generation == 4){
				price = TEEN_AFTER;
				}
			else if(generation == 5){
				price = ADULT_AFTER;
				}
			else if(generation == 6){
				price = CHILD_AFTER;
				} 
			break;
			
		case 3 :
			if(generation == 1){
				price = FREE;
				} 
			else if(generation == 2){
				price = BABY_DAY_TOTAL;
				}
			else if(generation == 3){
				price = CHILD_DAY_TOTAL;
				}
			else if(generation == 4){
				price = TEEN_DAY_TOTAL;
				}
			else if(generation == 5){
				price = ADULT_DAY_TOTAL;
				}
			else if(generation == 6){
				price = CHILD_DAY_TOTAL;
				}
			break;
			
		case 4 :
			if(generation == 1){
				price = FREE;
				} 
			else if(generation == 2){
				price = BABY_AFTER_TOTAL;
				}
			else if(generation == 3){
				price = CHILD_AFTER_TOTAL;
				}
			else if(generation == 4){
				price = TEEN_AFTER_TOTAL;
				}
			else if(generation == 5){
				price = ADULT_AFTER_TOTAL;
				}
			else if(generation == 6){
				price = CHILD_AFTER_TOTAL;
				}
			break;
	}
} 

// 주문개수 처리
void processOrderCount(){
	if(orderCount <= 10){
	countPrice = price * orderCount;
	}
} 

// 우대사항 처리 
void processDiscount(){
	switch(discount){
		case 1 :										// 우대사항 없음 
			discountPrice = countPrice;
			break;
		
		case 2 :										// 장애인 50% 우대, 종합/파크  (+동반1인) 
			discountPrice = countPrice * 0.5;
			break;
		
		case 3 :										// 국가유공자 50% 우대, 종합/파크  (+동반1인)
			discountPrice = countPrice * 0.5;
			break;
			
		case 4 :										// 휴가장병 49% 우대, 종합  (+동반1인)
			discountPrice = countPrice;
			if((ticketSelect == 3) || (ticketSelect == 4)){
				discountPrice = countPrice * 0.51;
				}
			break;
		
		case 5 :										// 임산부 50% 우대, 종합
			discountPrice = countPrice;
			if((ticketSelect == 3) || (ticketSelect == 4)){
				discountPrice = countPrice * 0.5;
				}
			break;
			
		case 6 :										// 다둥이 30% 우대, 종합
			discountPrice = countPrice;
			if((ticketSelect == 3) || (ticketSelect == 4)){
				discountPrice = countPrice * 0.5;
				}
			break;		
		}
}

// 발권 입력
void inputAll(){
	// 변수 초기화 
	todayYMD = 0, ticketSelect = 0, idNumber = 0, backIdNumber = 0, orderCount = 0, 	
	discount = 0, age = 0, generation = 0, price = 0, countPrice = 0, discountPrice = 0; 
	
	// 오늘 날짜 계산
	todayDate();
			
	//화면 출력 시작(오늘날짜) 
	printf("*************************** COCOLAND ************************* \n\t\t\t[TODAY : %d] \n\n", todayYMD);
	
	// 권종 선택 
	inputTicketSelect(); 

	// 주민번호 앞자리 입력 
	inputIdNumber();
	
	// 주민번호 뒷자리 입력 
	inputBackIdNumber();
	
	// 갯수 입력 
	inputOrderCount();
		
	// 우대사항 입력 
	inputDiscount();
} 

//발권 처리(+입력) 
void processAll(){
	do{
		// 발권 입력 
		inputAll();
		
		// 만나이 계산 
		ageCalculation();
		
		// 연령구분
		ageGeneration();
		
		// 나이별 가격 측정
		generationPrice();

		// 주문 개수 처리 
		processOrderCount();
		
		// 우대사항 처리 
		processDiscount();
		
		printf("\n ***** 가격은 %d원입니다. 감사합니다. *****\n", discountPrice);
		
		// 행렬에 입력사항 넣기 
		todayYMDArr[index] = todayYMD;
		ticketSelectArr[index] = ticketSelect;
		generationArr[index] = generation;
		orderCountArr[index] = orderCount;
		discountArr[index] = discount;
		discountPriceArr[index] = discountPrice;
		totalPrice += discountPrice;
		
		index++;
		
		printf("\n 계속 발권 하시겠습니까? \n 1. 티켓 발권\n 2. 종료\n\t");
		scanf("%d", &again);
		
	} while(again == 1);
		
		printf("\n COCOLAND를 이용해주셔서 감사합니다.\n"); 
} 

// 발권 출력
void printReceipt(){
	FILE * filePointer = fopen("report.csv", "a");
	printf("\n\n****************************** COCOLAND ******************************\n\n");
	printf("%10s\t   %6s  %2s  %8s  %15s \n", "선택사항", "연령", "매수", "가격", "우대사항\n");
			
	for (int i = 0; i < index; i++) {
		fprintf(filePointer, "%d, %d, %d, %d, %d, %d\n", todayYMDArr[i], ticketSelectArr[i], generationArr[i], orderCountArr[i], discountPriceArr[i], discountArr[i]);
		switch (ticketSelectArr[i]) {
			case 1:
				printf("%s %7s","파크이용권","1Day");
				break;
			case 2:
				printf("%s %7s","파크이용권","After4");
				break;
			case 3:						
				printf("%s %7s","종합이용권","1Day");
				break;
			case 4:
				printf("%s %7s","종합이용권","After4");
				break;
			default:
				break;
			}
		
		switch (generationArr[i]) {
			case 1:
				printf("  %5s", "영아");
				break;
			case 2:
				printf("  %5s", "유아");
				break;
			case 3:
				printf("  %5s", "어린이");
				break;
			case 4:
				printf("  %5s", "청소년");
				break;
			case 5:
				printf("  %5s", "어른");
				break;
			case 6:
				printf("  %5s", "고령");
				break;					 
		}
		
		printf("%3d 매%11d원\t",orderCountArr[i], discountPriceArr[i]) ;
				
		switch (discountArr[i]) {
			case 1:
				printf("%10s\n","없음");
				break;
			case 2:
				printf("%10s\n","장애인 우대");
				break;
			case 3:
				printf("%10s\n","국가유공자 우대");
				break;
			case 4:
				printf("%10s\n","휴가장병 우대");
				break;
			case 5:
				printf("%10s\n","임산부 우대");
				break;
			case 6:
				printf("%10s\n","다둥이 우대");
				break;
			default:
				break;
				}
			}
		
	printf("\n\n\n\t\t\t총액은 %d원 입니다.", totalPrice);
	printf("\n\n\n***************************** THANK YOU ******************************\n") ;
	
	printf("\n 새로운 주문을 받겠습니까? \n 1. 새로운 발권 2. 종료\n");
	scanf("%d", &next);
	
	fclose(filePointer);
} 


int main(){
	do { 
		processAll();		// 발권 입력 & 처리
		printReceipt();		// 영수증 출력
	}while(next == 1);
	
	return 0;
}
