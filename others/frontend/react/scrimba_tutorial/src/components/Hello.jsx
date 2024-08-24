import React from 'react'
import logo from "../assets/images/download.png"
import "../assets/styles/Hello.css"


const Hello = () => {
  return (
    <div className='body'>
      <nav className='nav'>
        < div className='logo' >
          <img src={logo} alt="react logo" className='image'/>
            <h3 className=''> React Facts  </h3>
        </ div >
         <div className='project'>
           <h4> React Course - Project 1 </h4>
         </div>
      </nav>

      <main>
        <h1>Fun Facts About React</h1>
        <ul>
          <li>Released In 2013</li>
          <li>Originally Created by Jordan Walke</li>
        </ul>
      </main>
    </div>
  )
}

export default Hello