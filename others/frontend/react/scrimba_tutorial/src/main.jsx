import React from 'react'
import ReactDOM from 'react-dom/client'
// import Hello from './components/Hello'
import Joke from './components/Joke'
import './index.css'
import Card from './components/Card'
import Katie from "./assets/images/download.png" 

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <>
      {/* <Hello/> */}
      {/* <Joke 
        setup="" 
        punchline="He just ransomware" 
        isPun={true}/> */}
        
      <Card 
        img={Katie}
        rating={4.8}
        reviewCount={6}
        country="USA"
        title="Life Lessons from Katie Zaferes"
        />

      
        
    </>
  </React.StrictMode>
);
