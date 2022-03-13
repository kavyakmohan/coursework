int isPrime(int x){

bool prime = true;

for (int i = 2; i < x; i++){
	if (x % i == 0){
		prime = false;
		break;
	}
}

return prime;		
}	
