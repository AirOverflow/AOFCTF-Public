var express = require('express');
var cookieParser = require('cookie-parser');
var escape = require('escape-html');
var serialize = require('node-serialize');
var app = express();
app.use(cookieParser())
app.set('view engine', 'ejs');
app.set('views', './views')

app.use(express.static('public'))
app.use('/assets', express.static(__dirname + 'public/assets'))
app.use('/vendor', express.static(__dirname + 'public/vendor'))
app.get('/profile', function(req, res) {
  try {

    if (req.cookies.streamer) { // Check if streamer cookie exists
        var str = new Buffer(req.cookies.streamer, 'base64').toString(); // Assuming it's base64 encoded
        var obj = serialize.unserialize(str);
        if (obj.streamername) {
            res.render('profile', {
                streamername: obj.streamername, // No need to escape here
                status: obj.status,
                age: obj.age,
                games: obj.games,
                friendsonline: obj.friendsonline,
                totalstreams: obj.totalstreams,
                clips: obj.clips
            });
        } else {
            // Handle the case where streamername is missing
            res.sendStatus(400); // Bad Request
        }
    } else {
        // Set the streamer cookie if it doesn't exist
        
        res.cookie('streamer', encodedStr, {
            maxAge: 900000,
            httpOnly: true
        });
        res.redirect('/profile'); // Redirect to /profile to render the page
    }
  }
  catch
  {
    var streamerCookie = { streamername: 'Rootxran', status: 'online', age: '20', games: '13', friendsonline: '4', totalstreams: '136', clips: '24'};
        var str = serialize.serialize(streamerCookie);
        var encodedStr = Buffer.from(str).toString('base64');
        
        res.cookie('streamer', encodedStr, {
            maxAge: 900000,
            httpOnly: true
        });
        res.redirect('/profile'); // Redirect to /profile to render the page
  }
});
//  res.send("Hello World");

// });
app.get('/', function(req, res) {
  res.render('index');
});
app.get('/details', function(req, res) {
  res.render('details');
});
app.get('/streams', function(req, res) {
  res.render('streams');
});
app.get('/browse', function(req, res) {
  res.render('browse');
});
app.post('/submit', function(req, res){
  res.json({ message: "Suggestion submitted" });
})
app.listen(8899);
console.log("Listening on port 8899...");
