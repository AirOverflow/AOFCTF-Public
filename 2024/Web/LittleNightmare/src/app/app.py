from aiohttp import web

app = web.Application()
app.add_routes([
    web.get('/', lambda request: web.FileResponse('./index.html')),
    web.static('/', './assets/', follow_symlinks=True)
])

web.run_app(app, port=1337)
