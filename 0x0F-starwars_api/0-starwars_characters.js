#!/usr/bin/node

const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], function x (error, response, body) {
  if (error) throw error;
  const chars = JSON.parse(body).characters;
  orderPrinter(chars, 0);
});

function orderPrinter (chars, n) {
  if (n === chars.length) { return; }
  request(chars[n], function x (error, response, body) {
    if (error) throw error;
    const name = JSON.parse(body).name;
    console.log(name);
    orderPrinter(chars, n + 1);
  });
}
