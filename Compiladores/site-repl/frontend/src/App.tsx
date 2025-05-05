import { useState } from 'react';
import axios from 'axios';

function App() {
  const [input, setInput] = useState('');
  const [output, setOutput] = useState<string[]>([]);

  const handleSubmit = async () => {
    if (!input.trim()) return;

    try {
      const response = await axios.post('http://localhost:3001/repl', { input });
      setOutput(prev => [...prev, `> ${input}`, response.data.result]);
    } catch (error: any) {
      setOutput(prev => [...prev, `> ${input}`, `Erro: ${error.response?.data?.error || 'Erro desconhecido'}`]);
    }

    setInput('');
  };

  return (
    <div style={{ padding: '2rem' }}>
      <h1>REPL</h1>
      <input
        type="text"
        value={input}
        onChange={e => setInput(e.target.value)}
        onKeyDown={e => e.key === 'Enter' && handleSubmit()}
        style={{ width: '100%', padding: '0.5rem', fontSize: '1rem' }}
      />
      <pre style={{ marginTop: '1rem', background: '#f5f5f5', padding: '1rem' }}>
        {output.map((line, i) => (
          <div key={i}>{line}</div>
        ))}
      </pre>
    </div>
  );
}

export default App;
