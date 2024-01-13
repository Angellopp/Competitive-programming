const { Client, GatewayIntentBits } = require('discord.js');
const client = new Client({ intents: [GatewayIntentBits.Guilds, GatewayIntentBits.GuildMessages] });
const token = 'MTE2NTUzMjk4OTI5MjI5ODMzMw.GUNlR5.koVfRKx1WqilpmXf3ovo3uEd5MqQy9bsNj1LlU';

client.on('ready', () => {
  console.log(`Bot iniciado como ${client.user.tag}`);
});

client.login(token);

client.on('messageCreate', (message) => {
  if (message.content.toLowerCase() === '!saludo') {
    // El bot responderá cuando se envíe el comando !saludo
    message.reply('¡Hola! Soy tu bot de Discord.');
  }
});



// client.on('messageCreate', (message) => {
//   if (message.content.startsWith('ping')) {
//     message.reply('pong 🏓!!');
//   }
// });

// const token = 'MTE2NTUzMjk4OTI5MjI5ODMzMw.GUNlR5.koVfRKx1WqilpmXf3ovo3uEd5MqQy9bsNj1LlU';

// client.login(token);


// const { Client } = require('discord.js');
// const client = new Client();
// const token = '<MTE2NTUzMjk4OTI5MjI5ODMzMw.GFReg9.YlaTUbls8bwwHg7TWZN7CUUBZF4-M3bBEJTpq>U';

// client.on('ready', () => {
//   console.log(`Bot iniciado como ${client.user.tag}`);
// });

// client.login(token);
