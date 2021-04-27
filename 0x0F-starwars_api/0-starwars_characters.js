#!/usr/bin/node
/**
 * 0x0F. Star Wars API
 */
const process = require('process');
const request = require('request');

if (process.argv.length !== 3) {
  process.exit(0);
}

const command1 = 'films/' + process.argv[2];
const urlApi = 'https://swapi-api.hbtn.io/api/';
const request1 = urlApi + command1;
let list = [];
let currentId = -1;
let limitMax = 0;

/**
 * loadUrlApi fn that connect with api
 *
 * @return void and load default fn to read names
 */
function loadUrlApi () {
  request(request1, function (error, response, body) {
    if (error) {
      console.log('error:', error);
      // throw error
      process.exit(1);
    }
    list = JSON.parse(body).characters;
    currentId = 0;
    if (Array.isArray(list)) {
      limitMax = list.length;
      loadFilmName();
    }
  });
}

/**
 * loadFilmName fn recursive that load film name
 *
 * @return void
 */
function loadFilmName () {
  if (limitMax > currentId) {
    request(list[currentId], function (error, response, body) {
      if (error) {
        console.log('error:', error);
        // throw error
        process.exit(1);
      }
      const name = JSON.parse(body).name;
      console.log(name);
      loadFilmName();
    });
    currentId++;
  }
}

/**
 * loadUrlApi fn run script
 */
loadUrlApi();
