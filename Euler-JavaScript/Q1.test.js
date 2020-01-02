import { multipleOf, sumOfMultiples } from './Q1';

describe("Q1", () => {
    describe("multipleOf", () => {
        it("should take a checked_number and a base_number, and return true if the checked_number is a multiple of the base_number", () => {
            const checked_number = 6;
            const base_number = 3;

            expect(multipleOf(checked_number, base_number)).toBe(true);
        });

        it("should take a checked_number and a base_number, and return false if the checked_number is not a multiple of the base_number", () => {
            const checked_number = 7;
            const base_number = 3;

            expect(multipleOf(checked_number, base_number)).toBe(false);
        });
    })

    describe("sumOfMultiples", () => {
        it("takes an upperLimit as an argument, and returns the sum of all numbers between 0 and the upperLimit that are multiples of either 3 or 5", () => {
            const upperLimit = 15; // 3, 5, 6, 9, 10, 12
            const expectedResult = 45;

            expect(sumOfMultiples(upperLimit)).toBe(expectedResult);
        })
    })
})