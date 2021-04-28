#!/usr/bin/node

const request = require('request');
const args = process.argv.slice(2);
const url = 'http://swapi-api.hbtn.io/api/films/' + args[0];
const options = {
    url: url,
    method: 'GET',
    headers: {
	Accept: 'application/json',
	'Accept-Charset': 'utf-8'
    }
};

request(options, (err, res, body) => {
    if (err) { throw err; }
    const myList = JSON.parse(body).characters;
    myList.forEach(function (element) {
	request({ url: element, method: 'GET' }, (err, res, body) => {
	    if (err) { console.log('Error'); }
	    console.log(JSON.parse(body).name);
	});
    });
});