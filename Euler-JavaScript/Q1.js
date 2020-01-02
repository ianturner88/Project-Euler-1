export function multipleOf(checked_number, base_number) {
    return checked_number % base_number === 0;
}

export function sumOfMultiples(upperLimit) {
    let answer = 0;

    for (let i = 0; i < upperLimit; i++) {
        if (multipleOf(i, 3) || multipleOf(i, 5)) {
            answer += i;
        }
    }
    
    return answer;
}

console.log(sumOfMultiples(1000));