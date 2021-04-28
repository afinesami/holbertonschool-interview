#!/usr/bin/node
/**
 * 0x0F. Star Wars API
 */

const args = process.argv.slice(2);
if (args < 1) {
  console.log('Error');
  process.exit(1);
}

const episode = args[0];

const url = 'https://swapi-api.hbtn.io/api/films/' + episode;
const request = require('request');
let characters = [];
request(url, (err, resp, body) => {
  if (err || resp.statusCode !== 200) console.log(err);
  else characters = JSON.parse(body).characters;
  const size = Object.keys(characters).length;
  const array = Array(size).fill();
  let data = 0;
  for (let i = 0; i < size; i++) {
    request(characters[i], (erro, respo, bodys) => {
      if (erro || respo.statusCode !== 200) console.log(erro);
      else {
        array[i] = JSON.parse(bodys).name;
        data++;
      }
      if (data === size) {
        for (let j = 0; j < size; j++) {
          console.log(array[j]);
        }
      }
    }

    );
  }
});
