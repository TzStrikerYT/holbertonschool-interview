#!/usr/bin/node
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;
request(url, (error, res, body) => {
  if (!error) {
    const res = JSON.parse(body);
    const characters = res.characters;
    if (characters.length > 0) {
      orderPrinter(0, characters[0], characters, characters.length);
    }
  } else {
    console.log(error);
  }
});
function orderPrinter (index, urlChar, characters, limit) {
  if (index === limit) {
    return;
  }
  request(urlChar, function (error, res, body) {
    if (!error) {
      const res = JSON.parse(body);
      console.log(res.name);
      index++;
      orderPrinter(index, characters[index], characters, limit);
    } else {
      console.error('error:', error);
    }
  });
}
