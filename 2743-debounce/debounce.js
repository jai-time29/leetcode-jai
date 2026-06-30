/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */



var debounce = function(fn, t) {

    let timer = null;

    return function(...args) {

        // cancel previous execution
        if(timer !== null) {
            clearTimeout(timer);
        }


        // schedule new execution
        timer = setTimeout(() => {

            fn(...args);

        }, t);

    };
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */