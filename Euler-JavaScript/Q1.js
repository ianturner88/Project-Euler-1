function multipleOfBaseNumber(number_being_checked, base_number) {
    return number_being_checked % base_number === 0;   
}

function sumOfMultiples() {
    let answer = 0;

    for (let i = 0; i < 1000; i++) {
        if (multipleOfBaseNumber(i, 3) || multipleOfBaseNumber(i, 5)) {
            answer += i;
        }
    }

    return answer;
}

console.log("The answer is: ", sumOfMultiples());