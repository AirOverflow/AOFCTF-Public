const puppeteer = require('puppeteer');
const fs = require('fs');

let CONFIG = {
    APPNAME: process.env['APPNAME'] || "Katana",
    APPURL: process.env['APPURL'] || "http://127.0.0.1:3000",
    APPURLREGEX: process.env['APPURLREGEX'],
    APPFLAG: process.env['APPFLAG'],
    APPLIMITTIME: Number(process.env['APPLIMITTIME'] || "60"),
    APPLIMIT: Number(process.env['APPLIMIT'] || "5"),
}
function readFileAndSetFlag() {
    return new Promise((resolve, reject) => {
        fs.readFile("flag.txt", 'utf8', (err, data) => {
            if (err) {
                reject(err);
                return;
            }
            CONFIG.APPFLAG = data.trim();
            resolve();
        });
    });
}
readFileAndSetFlag()
    .then(() => {
        console.table(CONFIG);
    })
    .catch((err) => {
        console.error('Error reading file:', err);
    });

function sleep(s){
    return new Promise((resolve)=>setTimeout(resolve, s))
}

const initBrowser = puppeteer.launch({
    executablePath: "/usr/bin/chromium-browser",
    headless: true,
    args: [
        '--disable-dev-shm-usage',
        '--no-sandbox',
        '--disable-setuid-sandbox',
        '--disable-gpu',
        '--no-gpu',
        '--disable-default-apps',
        '--disable-translate',
        '--disable-device-discovery-notifications',
        '--disable-software-rasterizer',
        '--disable-xss-auditor'
    ],
    ipDataDir: '/home/bot/data/',
    ignoreHTTPSErrors: true
});

console.log("Bot started...");

module.exports = {
    name: CONFIG.APPNAME,
    urlRegex: CONFIG.APPURLREGEX,
    rateLimit: {
        windowS: CONFIG.APPLIMITTIME,
        max: CONFIG.APPLIMIT
    },
    bot: async (urlToVisit) => {
        const browser = await initBrowser;
        const context = await browser.createBrowserContext()
        try {
            // Goto main page
            const page = await context.newPage();

            // Set Flag
            await page.setCookie({
                name: "flag",
                httpOnly: false,
                value: CONFIG.APPFLAG,
                url: "http://127.0.0.1:3000"
            })

            // Visit URL from user
            console.log(`bot visiting ${urlToVisit}`)
            await page.goto(urlToVisit, {
                waitUntil: 'networkidle2'
            });
            await sleep(15000);

            // Close
            console.log("browser close...")
            await context.close()
            return true;
        } catch (e) {
            console.error(e);
            await context.close();
            return false;
        }
    }
}
