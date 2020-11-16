#!/usr/bin/node
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;

request(url, (error, response, body) => {
  if (!error) {
    const res = JSON.parse(body);
    const characters = res.characters;
    if (characters.length > 0) {
      characterRequest(0, characters[0], characters, characters.length);
    }
  } else {
    console.log(error);
  }
});

function characterRequest (charIndex, urlChar, characters, limit) {
  if (charIndex === limit) {
    return;
  }
  request(urlChar, function (error, response, body) {
    if (!error) {
      const response = JSON.parse(body);
      console.log(response.name);
      charIndex++;
      characterRequest(charIndex, characters[charIndex], characters, limit);
    } else {
      console.error('error:', error);
    }
  });
}
